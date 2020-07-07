#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
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

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

int main() {
    int n;
    cin >> n;

    struct Norm {
        double x, y, c;
    };

    vector<Norm> v(n);
    rep(i, n) cin >> v[i].x >> v[i].y >> v[i].c;

    double floor = 0, ceil = INF;
    rep(_, 1e5) {
        double mid = (floor + ceil) / 2;

        double l = -INF, r = INF, u = INF, d = -INF;
        bool ok = [&] {
            for (Norm norm : v) {
                double nl = norm.x - mid / norm.c;
                double nr = norm.x + mid / norm.c;
                double nu = norm.y + mid / norm.c;
                double nd = norm.y - mid / norm.c;

                if (r < nl || nr < l || u < nd || nu < d) {
                    return false;
                }

                cmax(l, nl);
                cmin(r, nr);
                cmin(u, nu);
                cmax(d, nd);
            }
            return true;
        }();

        if (ok) ceil = mid;
        else floor = mid;

    }
    cout << setprecision(20) << ceil << endl;
}
