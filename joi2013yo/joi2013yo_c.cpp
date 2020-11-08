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

bool check(string &s, string &t) {

    for (int i = 0; (t.size() - 1) * (i + 1) + 1 <= s.size(); i++) {
        int len = (t.size() - 1) * (i + 1) + 1;
        for (int j = 0; j + len <= s.size(); j++) {
            string u = s.substr(j, len);

            string w;
            rep(k, t.size() - 1) {
                w += u[k * (i + 1)];
            }
            w.push_back(u.back());

            if (w == t) return true;

        }

    }
    return false;
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    vector<string> v(n);
    rep(i, n) cin >> v[i];

    int ans = 0;
    rep(i, n) if (check(v[i], s)) ans++;
    cout << ans << endl;
}
