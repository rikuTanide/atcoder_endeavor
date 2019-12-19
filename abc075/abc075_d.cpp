#include <bits/stdc++.h>
#include <cmath>


#include <assert.h>    // LON
#include <math.h>    // sqrt()


using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX;
const ll MINF = -10e10;
//const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;

class Conv {
    ll cursor = 0;
    map<ll, ll> to_short; // <original, small >
    map<ll, ll> to_long; // <small, original>


public:
    void set(ll original) {
        if (to_short.find(original) != to_short.end()) {
            return;
        }
        to_long[cursor] = original;
        to_short[original] = cursor;
        cursor++;
    }

    ll revert(ll after) {
        assert(to_long.find(after) != to_long.end());
        return to_long[after];
    }

    ll convert(ll original) {
        assert(to_short.find(original) != to_short.end());
        return to_short[original];
    }

    ll next() {
        return cursor;
    }

};

class MatrixSum {
    vector<vector<ll>> sum;
public:
    MatrixSum(ll x, ll y) {
        sum = vector<vector<ll>>(x, vector<ll>(y));
    }

    void add(ll x, ll y) {
        sum[x][y]++;
    }

    ll get(ll x, ll y) {
        if (x == -1 || y == -1) {
            return 0;
        }
        if (x == sum.size() || y == sum[x].size()) {
            return 0;
        }
        return sum[x][y];
    }

    void setUp() {
        for (ll x = 0; x < sum.size(); x++) {
            for (ll y = 0; y < sum[x].size(); y++) {
                sum[x][y] += get(x - 1, y) + get(x, y - 1) - get(x - 1, y - 1);
            }
        }
    }

    ll getSum(ll xs, ll ys, ll xe, ll ye) {
        return get(xe, ye) - get(xs - 1, ye) - get(xe, ys - 1) + get(xs - 1, ys - 1);
    }

};

struct Match {
    ll sx, sy, ex, ey;
};

int main() {

    ll n, k;
    cin >> n >> k;

    vector<P> vertexes(n);
    rep(i, n) {
        ll x, y;
        cin >> x >> y;
        vertexes[i].first = x;
        vertexes[i].second = y;
    }


    Conv convX;
    Conv convY;

    {
        sort(vertexes.begin(), vertexes.end(), [](P p, P q) {
            return p.first < q.first;
        });
        for (P p : vertexes) {
            convX.set(p.first);
        }
    }
    {
        sort(vertexes.begin(), vertexes.end(), [](P p, P q) {
            return p.second < q.second;
        });
        for (P p : vertexes) {
            convY.set(p.second);
        }
    }
    vector<P> short_vertexes(n);
    rep(i, n) {
        short_vertexes[i].first = convX.convert(vertexes[i].first);
        short_vertexes[i].second = convY.convert(vertexes[i].second);
    }

    MatrixSum matrixSum(convX.next(), convY.next());

    for (P p : short_vertexes) {
        matrixSum.add(p.first, p.second);
    }
    matrixSum.setUp();

    vector<Match> matches;

    for (ll xs = 0; xs < convX.next(); xs++) {
        for (ll xe = xs + 1; xe < convX.next(); xe++) {
            for (ll ys = 0; ys < convY.next(); ys++) {
                for (ll ye = ys + 1; ye < convY.next(); ye++) {
                    ll sum = matrixSum.getSum(xs, ys, xe, ye);
                    if (sum == k) {
                        matches.push_back({xs, ys, xe, ye});
                    }
                }
            }
        }
    }

    ll ans = INF;
    for (Match match : matches) {
        ll sx = convX.revert(match.sx);
        ll sy = convY.revert(match.sy);
        ll ex = convX.revert(match.ex);
        ll ey = convY.revert(match.ey);

        ll width = abs(sx - ex);
        ll height = abs(sy - ey);
        ll s = width * height;
        cmin(ans, s);
    }

    cout << ans << endl;

}