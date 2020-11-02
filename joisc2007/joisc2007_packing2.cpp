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

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
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

int main() {

    int n;
    cin >> n;

    vector<vector<double>> dots = {
            {-0.357600762304199615412885499473, -0.357600762304199615412885499473},
            {-0.072802286912598846238656498419, -0.357600762304199615412885499473},
            {0.343296731820388214990403085534,  -0.343296731803866529105436700301},
            {0.082506559635700761635644080357,  -0.118876373585290223229706933818},
            {-0.357600762304199615412885499473, -0.072802286912598846238656498419},
            {0.357600762304199615412885499473,  -0.045165104137782354317816528877},
            {-0.118876373585290223229706933818, 0.082506559635700761635644080357},
            {0.156217829083208630547534485298,  0.156217829083208630547534485298},
            {-0.343296731806752502811117072826, 0.343296731805862110687045277782},
            {-0.045165104137782354317816528877, 0.357600762304199615412885499473},
            {0.357600762304199615412885499473,  0.357600762304199615412885499473},
    };

    ll dig = 1e8;

    for (auto e : dots) {
        cout << ll((e[0] + 0.5) * dig) << ' ' << ll((e[1] + 0.5) * dig) << endl;
//        cout << e[0] + 0.5 << ' ' << e[1] + 0.5 << endl;
//        cout << e[0] << ' ' << e[1] << endl;
    }

}
