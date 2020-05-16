#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<double, double> P;
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
    int m;
    ll k;
    cin >> m >> k;

    if (k >= (1ll << m)) {
        cout << -1 << endl;
        ret();
    }

    if (m == 1) {
        if (k == 0) {
            printf("0 0 1 1\n");
            ret();
        } else {
            cout << -1 << endl;
            ret();
        }
    }

    vector<ll> v;
    rep(i, 1ll << m) {
        if (i != k)v.push_back(i);
    }
    vector<ll> u = v;
    reverse(u.begin(), u.end());

    vector<ll> a;
    rep(i, v.size()) {
        a.push_back(v[i]);
    }
    a.push_back(k);
    rep(i, u.size()) {
        a.push_back(u[i]);
    }
    a.push_back(k);

    for (ll l : a) cout << l << ' ';
    cout << endl;
}