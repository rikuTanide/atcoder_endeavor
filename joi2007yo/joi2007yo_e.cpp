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

struct Test {
    int a, b, c, s;
};

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int n;
    cin >> n;

    vector<Test> tests(n);
    for (Test &t: tests) cin >> t.a >> t.b >> t.c >> t.s, t.a--, t.b--, t.b -= a, t.c--, t.c -= a, t.c -= b;

    vector<char> as(a, '?'), bs(b, '?'), cs(c, '?');

    while (true) {
        vector<char> next_as = as, next_bs = bs, next_cs = cs;

        for (Test t : tests) {
            if (t.s == 1) {
                next_as[t.a] = 'o';
                next_bs[t.b] = 'o';
                next_cs[t.c] = 'o';
            } else {
                if (next_as[t.a] == 'o' && next_bs[t.b] == 'o') {
                    assert(next_cs[t.c] != 'o');
                    next_cs[t.c] = 'x';
                } else if (next_bs[t.b] == 'o' && next_cs[t.c] == 'o') {
                    assert(next_as[t.a] != 'o');
                    next_as[t.a] = 'x';
                } else if (next_as[t.a] == 'o' && next_cs[t.c] == 'o') {
                    assert(next_bs[t.b] != 'o');
                    next_bs[t.b] = 'x';
                }
            }
        }

        if (next_as == as && next_bs == bs && next_cs == cs) break;
        as = next_as;
        bs = next_bs;
        cs = next_cs;
    }

    for (char c : as) {
        if (c == 'x') cout << 0 << endl;
        if (c == 'o') cout << 1 << endl;
        if (c == '?') cout << 2 << endl;
    }
    for (char c : bs) {
        if (c == 'x') cout << 0 << endl;
        if (c == 'o') cout << 1 << endl;
        if (c == '?') cout << 2 << endl;
    }
    for (char c : cs) {
        if (c == 'x') cout << 0 << endl;
        if (c == 'o') cout << 1 << endl;
        if (c == '?') cout << 2 << endl;
    }
}
