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

    vector<ll> v(n);
    rep(i, n) cin >> v[i];

    map<ll, int> m;
    for (ll l : v) m[l]++;

    if (m.find(0) != m.end() && m[0] == n) {
        cout << "Yes" << endl;
        ret();
    }

    vector<ll> keys;
    for (auto e : m)keys.push_back(e.first);

    if (keys.size() == 2 && keys[0] == 0 && m[0] == n / 3 * 2) {
        cout << "Yes" << endl;
        ret();
    }

    if (keys.size() == 3 && m[keys[0]] * 3 == n && m[keys[1]] * 3 == n && m[keys[2]] * 3 == n &&
        (keys[0] ^ keys[1] ^ keys[2]) == 0) {
        cout << "Yes" << endl;
        ret();
    }
    cout << "No" << endl;
}
