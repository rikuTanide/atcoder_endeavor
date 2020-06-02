#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const long double EPS = 1e-9;

#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<char> &o) {
    string a;
    in >> a;
    for (char c : a) o.insert(c);
    return in;
}

std::istream &operator>>(std::istream &in, queue<int> &o) {
    ll a;
    in >> a;
    o.push(a);
    return in;
}

bool contain(set<char> &s, char a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;

#define repr(i, n) for(int i = n-1;i >= 0;--i)

ll get(vector<vector<ll>> v) {
    int h = v.size();
    int w = v.front().size();
    vector<vector<ll>> sum(h + 1, vector<ll>(w + 1));
    rep(i, h)
        rep(j, w) {
            sum[i][j + 1] = sum[i][j] + v[i][j];
        }

    vector<ll> dpL(w + 1, -INF), dpR(w + 1, -INF);


    for (int y2 = 1; y2 < w; y2++) {
//    FOR(y2,1, W) {
        dpL[y2] = dpL[y2 - 1];
        //print(dpL[y2]);
        rep(y1, y2) {
            ll mn = 0;
            ll cum = 0;
            rep(x, h) {
                cum += sum[x][y2] - sum[x][y1];
                cmax(dpL[y2], cum - mn);
                mn = min(mn, cum);
            }
        }
    }
    repr(y1, w) {
        dpR[y1] = dpR[y1 + 1];
        for (int y2 = w; y2 >= y1 + 1; y2--) {
            ll mn = 0;
            ll cum = 0;
            rep(x, h) {
                cum += sum[x][y2] - sum[x][y1];
                cmax(dpR[y1], cum - mn);
                mn = min(mn, cum);
            }
        }
    }
    ll ans = -2e9;
    for (int y = 1; y < w; y++) {
        ans = max(ans, dpL[y] + dpR[y]);
    }
    return ans;
}

class MatrixSum {
    vector<vector<ll>> sum;
public:
    MatrixSum(ll x, ll y) {
        sum = vector<vector<ll>>(x, vector<ll>(y));
    }

    void set(ll x, ll y, ll v) {
        sum[x][y] = v;
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

struct Point {
    int sx, ex, sy, ey;
};

int main() {

    int h, w;
    cin >> h >> w;

    vector<vector<ll>> a(h, vector<ll>(w));
    vector<vector<ll>> b(w, vector<ll>(h));
    rep(y, h) rep(x, w) {
            ll v;
            cin >> v;
            a[y][x] = v;
            b[x][y] = v;
        }

    cout << max(get(a), get(b)) << endl;
}
