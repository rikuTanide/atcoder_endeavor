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

struct Time {
    int h, m, s;

    Time sub(Time other) {
        Time ans = *this;
        ans.s -= other.s;
        if (ans.s < 0) {
            ans.m--;
            ans.s += 60;
        }
        ans.m -= other.m;
        rep(_, 2)if (ans.m < 0) {
                ans.h--;
                ans.m += 60;
            }
        ans.h -= other.h;
        return ans;
    }

    friend std::istream &operator>>(std::istream &in, Time &o) {
        in >> o.h >> o.m >> o.s;
        return in;
    }
};

void solve(Time start, Time end) {

    Time sub = end.sub(start);
    printf("%d %d %d\n", sub.h, sub.m, sub.s);

}


int main() {
    rep(_, 3) {
        Time start, end;
        cin >> start >> end;
        solve(start, end);
    }
}