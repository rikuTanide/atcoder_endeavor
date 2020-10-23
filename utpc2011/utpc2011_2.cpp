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

bool check(int n, int i, char a, char b) {
    if (n % 2 == 1 && i == n / 2) return a == 'i' || a == 'w';

    if (a == 'i' || a == 'w') {
        return a == b;
    }

    if (a == '(') return b == ')';
    if (a == ')') return b == '(';

    return false;
}

int main() {
    string s;
    cin >> s;

    string t = s;

    reverse(t.begin(), t.end());

    int ans = 0;

    rep(i, (s.size() + 1) / 2) {

        if (check(s.size(), i, s[i], t[i])) continue;

        ans++;
    }

    cout << ans << endl;

}
