#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
typedef pair <ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<int> &o) {
    int a;
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

typedef priority_queue <ll, vector<ll>, greater<ll>> PQ_ASK;

typedef long double ld;

struct N {
    ld x, y, r;
};

struct M {
    ld x, y;
};

std::istream &operator>>(std::istream &in, N &o) {
    in >> o.x >> o.y >> o.r;
    return in;
}

std::istream &operator>>(std::istream &in, M &o) {
    in >> o.x >> o.y;
    return in;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector <N> ns(n);
    rep(i, n)cin >> ns[i];
    vector <M> ms(m);
    rep(i, m) cin >> ms[i];

    auto get = [&](int i, ld mid) -> N {
        if (i < n) {
            return ns[i];
        }
        i -= n;
        M mt = ms[i];

        return N{
                mt.x, mt.y, mid,
        };
    };

    auto intersect = [&](N a, N b) -> bool {
        ld x = a.x - b.x;
        ld y = a.y - b.y;

        ld xx = x * x;
        ld yy = y * y;

        return sqrtl(xx + yy) < (a.r + b.r);
    };

    auto check = [&](ld mid) {
        for (int i = 0; i < (n + m); i++) {
            for (int j = i + 1; j < (n + m); j++) {
                N a = get(i, mid);
                N b = get(j, mid);

                if (intersect(a, b)) {
                    return false;
                }
            }
        }
        return true;
    };


    ld floor = 0, ceil = INF;
    for (N ni: ns) cmin(ceil, ni.r);
    rep(_, 1e3) {
        ld mid = (floor + ceil) / 2;
        bool ok = check(mid);
        if (ok) floor = mid;
        else ceil = mid;
    }

    cout << setprecision(20) << floor << endl;

}
