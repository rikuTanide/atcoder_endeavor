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

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

int main() {
    int n;
    cin >> n;
    vector<string> v(n);
    rep(i, n) cin >> v[i];

    for (string &s:v) reverse(s.begin(), s.end());

    ll ans = 0;

    auto check = [&](string &s, string &tmp) -> bool {
        if (s == tmp) return false;
        return find(v.begin(), v.end(), tmp) != v.end();
    };

    for (string &s: v) {

        string tmp;
        vector<int> used(26, 0);
        for (char c : s) used[c - 'a']++;
        for (char c : s) {

            rep(i, 26) {
                if (used[i] == 0) continue;
                tmp.push_back('a' + i);
                if (check(s, tmp)) ans++;
                tmp.pop_back();
            }
            tmp.push_back(c);
            used[c - 'a']--;
        }

    }
    cout << ans << endl;

}
