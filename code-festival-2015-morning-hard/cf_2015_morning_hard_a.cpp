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

    vector<ll> othellos(n);
    rep(i, n) cin >> othellos[i];

    vector<ll> rt(n);
    rt[n - 2] = othellos[n - 1];
    for (int i = n - 3; i >= 0; i--) {
        rt[i] = (rt[i + 1] + othellos[i + 1] + 1);
    }

//    for (int i = n - 2; i >= 0; i--) {
//        cout << rt[i] << ' ';
//    }
//    cout << endl;

    vector<ll> r(n);
    for (int i = n - 2; i >= 0; i--) {
        r[i] = r[i + 1] + rt[i];
    }

//    for (int i = n - 2; i >= 0; i--) {
//        cout << r[i] << ' ';
//    }
//    cout << endl;


    vector<ll> lt(n);

    lt[1] = othellos[0];
    for (int i = 2; i < n; i++) {
        lt[i] = lt[i - 1] + othellos[i - 1] + 1;
    }

//    for (int i = 1; i < n; i++) {
//        cout << lt[i] << ' ';
//    }
//    cout << endl;

    vector<ll> l(n);
    for (int i = 1; i < n; i++) {
        l[i] = l[i - 1] + lt[i];
    }

//    for (int i = 1; i < n; i++) {
//        cout << l[i] << ' ';
//    }
//    cout << endl;
//
//    rep(i, n) cout << r[i] << ' ';
//    cout << endl;
//    rep(i, n) cout << l[i] << ' ';
//    cout << endl;

    ll ans = INF;

    rep(i, n) if (i % 2 == 0) cmin(ans, r[i] + l[i]);
    cout << ans << endl;

}
