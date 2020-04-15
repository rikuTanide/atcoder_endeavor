#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

std::istream &operator>>(std::istream &in, set<int> &o) {
    ll a;
    in >> a;
    o.insert(a);
    return in;
}

std::istream &operator>>(std::istream &in, queue<int> &o) {
    ll a;
    in >> a;
    o.push(a);
    return in;
}

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;
const int mod = 1000000007;

class MatrixSum {
    vector<vector<ll>> sum;
public:
    MatrixSum(ll x, ll y) {
        sum = vector<vector<ll>>(x, vector<ll>(y));
    }

    void add(ll x, ll y) {
        sum[x][y]++;
    }

    void add(ll x, ll y, ll value) {
        sum[x][y] += value;
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

int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<ll>> chocolate(h, vector<ll>(w));
    rep(y, h) rep(x, w) cin >> chocolate[y][x];
    MatrixSum black(w, h), white(w, h);
    rep(y, h) rep(x, w)if (y % 2 == x % 2) black.add(x, y, chocolate[y][x]); else white.add(x, y, chocolate[y][x]);
    black.setUp();
    white.setUp();

    ll ans = 0;
    for (int ys = 0; ys < h; ys++) {
        for (int ye = ys; ye < h; ye++) {
            for (int xs = 0; xs < w; xs++) {
                for (int xe = xs; xe < w; xe++) {
                    ll bsum = black.getSum(xs, ys, xe, ye);
                    ll wsum = white.getSum(xs, ys, xe, ye);
                    if (bsum != wsum) continue;
                    ll nw = xe - xs + 1;
                    ll nh = ye - ys + 1;
                    ll now_a = nw * nh;
                    cmax(ans, now_a);
                }
            }
        }
    }
    cout << ans << endl;
}

