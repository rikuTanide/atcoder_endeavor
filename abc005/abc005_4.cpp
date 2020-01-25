#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
//typedef long long ll;
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = 10e15;
const ll MINF = -10e10;
const int INF = INT_MAX / 100;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("~/Downloads/02.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;

class MatrixSum {
    vector<vector<ll>> sum;
public:
    MatrixSum(ll x, ll y) {
        sum = vector<vector<ll>>(x, vector<ll>(y));
    }

    void set(ll x, ll y, ll v) {
        sum[x][y] = v;
    }

    void add(ll x, ll y) {
        sum[x][y]++;
    }

    ll get(ll x, ll y) {
        if (x < -1 || y < -1) {
            return 0;
        }
        if (x >= sum.size() || y >= sum[x].size()) {
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

vector<P> pairs(int n, int p) {
    vector<P> pr;
    for (int x = 1; x <= n; x++) {
        int h = 0;
        for (int y = 1; y <= n; y++) {
            if (x * y <= p) h = y;
        }
        if (h > 0)pr.emplace_back(x, h);
    }
    return pr;
}

int main() {
    ll n;
    cin >> n;

    MatrixSum ms(n, n);
    rep(y, n) {
        rep(x, n) {
            ll d;
            cin >> d;
            ms.set(y, x, d);
        }
    }
    ms.setUp();

    int q;
    cin >> q;
    rep(i, q) {
        int p;
        cin >> p;

        ll ans = 0;

        auto rects = pairs(n, p);
        for (P rect : rects) {
            for (int y = 0; y < n - rect.second + 1; y++) {
                for (int x = 0; x < n - rect.first + 1; x++) {
                    ll now = ms.getSum(x, y, x + rect.first - 1, y + rect.second - 1);
                    cmax(ans, now);
                }
            }
        }

        cout << ans << endl;
    }
}
