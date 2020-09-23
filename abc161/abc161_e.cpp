#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;
#include "atcoder/all"

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
    int n, k, c;
    string s;
    cin >> n >> k >> c >> s;

    vector<int> right(n, -1);
    {
        queue<int> q;
        rep(i, k) q.push(i);

        for (int i = 0; i < n; i++) {
            if (s[i] == 'x') continue;
            if (q.empty()) continue;
            right[i] = q.front();
            q.pop();
            i += c;
        }

    }
    vector<int> left(n, -1);
    {
        queue<int> q;
        rep(i, k) q.push(k - 1 - i);

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == 'x') continue;
            if (q.empty()) continue;
            left[i] = q.front();
            q.pop();
            i -= c;
        }

    }

    rep(i, n) {
        if (left[i] == -1) continue;
        if (right[i] == -1) continue;
        if (left[i] != right[i]) continue;
        cout << i + 1 << endl;
    }


}
