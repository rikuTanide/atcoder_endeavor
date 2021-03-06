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

bool check(char a, char b) {
    if (a == '(') return b == ')';
    if (a == ')') return b == '(';

    if (a == '[') return b == ']';
    if (a == ']') return b == '[';

    if (a == '{') return b == '}';
    if (a == '}') return b == '{';

    return false;
}

bool check_all(string &s) {
    if (s.size() % 2 == 0) return false;
    if (s.size() < 3) return false;

    int center = s.size() / 2;

    if (s[center] != 'w') return false;
    if (s[center + 1] != 'i') return false;
    if (s[center - 1] != 'i') return false;

    for (int i = 0; i < center - 1; i++) {
        int j = s.size() - 1 - i;
        if (!check(s[i], s[j])) return false;
    }
    return true;

}

int main() {

    string s;
    cin >> s;
    int ans = 0;
    rep(i, 1 << s.size()) {

        string tmp;

        rep(j, s.size()) {
            if ((i >> j) & 1) {
                tmp.push_back(s[j]);
            }
        }

        if (check_all(tmp)) {
            int now = __builtin_popcount(i);
            cmax(ans, now);
        }

    }
    cout << ans << endl;

}
