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

struct M {
    char method;
    ll value;

    int type() {
        if (method == '+') return 0;
        else if (method == '*') return 1;
        return 2;
    }

};

int main() {
    int n;
    cin >> n;

    vector<M> v(n);
    rep(i, n) cin >> v[i].method >> v[i].value;
    sort(v.begin(), v.end(), [](M m1, M m2) {
        return m1.type() < m2.type();
    });


    v = [&] {
        vector<M> v2;
        for (M m : v)
            if (m.method == '+' || (m.method == '*' && m.value > 0)) {
                v2.push_back(m);
            }
        return v2;
    }();


    ll ans = 0;
    for (M m : v) {
        if (m.method == '+') ans += m.value;
        else ans *= m.value;
    }
    cout << ans << endl;


}
