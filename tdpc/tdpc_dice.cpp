#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;
//#include "atcoder/all"

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

bool equal(double a, double b) {
//    return fabs(a - b) < DBL_EPSILON;
    return fabs(a - b) < EPS;
}

template<class T>
std::istream &operator>>(std::istream &in, set<T> &o) {
    T a;
    in >> a;
    o.insert(a);
    return in;
}

template<class T>
std::istream &operator>>(std::istream &in, queue<T> &o) {
    ll a;
    in >> a;
    o.push(a);
    return in;
}

template<class T>
bool contain(set<T> &s, T a) { return s.find(a) != s.end(); }

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;


map<ll, int> factorize(ll n) {
    map<ll, int> res;

    for (ll i = 2; i * i <= n; i++) {
        if (n % i != 0) {
            continue;
        }
        res[i] = 0;
        while (n % i == 0) {
            n /= i;
            res[i]++;
        }
    }

    if (n != 1) res[n] = 1;
    return res;
}


int main() {
    vector<vector<vector<double>>> prev(201, vector<vector<double>>(101, vector<double>(101, 0)));
    prev[0][0][0] = 1;

    int n;
    ll d;
    cin >> n >> d;
    auto f = factorize(d);

    for (auto e : f) {
        if (e.first != 2 && e.first != 3 && e.first != 5) {
            cout << 0 << endl;
            ret();
        }
    }


    rep(_, n) {
        vector<vector<vector<double>>> next(201, vector<vector<double>>(101, vector<double>(101, 0)));
        rep(a, 201) {
            rep(b, 101) {
                rep(c, 101) {

                    auto add = [&](int p, int q, int r) {
                        if (p > 200) return;
                        if (q > 100) return;
                        if (r > 100) return;

                        next[p][q][r] += prev[a][b][c] * 1.0 / 6;
                    };

                    add(a, b, c);
                    add(a + 1, b, c);
                    add(a, b + 1, c);
                    add(a + 2, b, c);
                    add(a, b, c + 1);
                    add(a + 1, b + 1, c);

                }
            }
        }
        swap(prev, next);
    }

    double ans = 0;
    rep(a, 201) {
        rep(b, 101) {
            rep(c, 101) {
                if (a < f[2]) continue;
                if (b < f[3]) continue;
                if (c < f[5]) continue;
                ans += prev[a][b][c];
            }
        }
    }
    cout << setprecision(20) << ans << endl;
}
