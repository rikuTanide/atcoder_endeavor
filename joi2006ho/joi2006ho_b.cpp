#include <bits/stdc++.h>
//#include "atcoder/all"
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

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

string solve(string s) {
    s += '*';
    vector<P> v;
    int prev = -1;
    int count = -1;

    rep(i, s.size()) {
        char c = s[i];
        int j = c - '0';
        if (j != prev) {
            v.push_back({count, prev});

            prev = j;
            count = 1;
        } else {
            count++;
        }
    }

    string ans;
    rep(i, v.size()) {
        if (i == 0) continue;

        P p = v[i];
        ans += to_string(p.first);
        ans += to_string(p.second);

    }

    return ans;
}

int main() {
    int n;
    string s;
    cin >> n >> s;


    rep(_, n) {
        s = solve(s);
    }

    cout << s << endl;

}