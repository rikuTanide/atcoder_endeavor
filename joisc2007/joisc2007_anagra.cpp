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

ll fac(ll n) {
    ll ans = 1;
    for (int i = 1; i <= n; i++) ans *= i;
    return ans;
}

ll rec(string s) {
    if (s.size() == 1) return 1;

    char top = s.back();

    vector<int> count(26, 0);
    for (char c : s) count[c - 'A']++;

    set<char> smaller_set;
    for (char c : s) if (c < top) smaller_set.insert(c);

    ll sum = 0;
    for (char c : smaller_set) {
        vector<int> _count = count;
        _count[c - 'A']--;

        ll size = accumulate(_count.begin(), _count.end(), 0ll);
        ll all = fac(size);

        for (int i : _count) all /= fac(i);

        sum += all;
    }

    s.pop_back();
    return sum + rec(s);

}

int main() {
    string s;
    cin >> s;

    reverse(s.begin(), s.end());

    ll ans = rec(s);
    cout << ans << endl;
}
