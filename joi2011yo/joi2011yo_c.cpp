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

ll conv_left_up(ll n, ll x) {
    if (x <= (n + 1) / 2) return x;
    if (n % 2 == 0) return (n / 2) - (x - (n / 2 + 1));
    else return (n / 2 + 1) - (x - (n / 2 + 1));
}

ll conv_from_center(ll n, ll x) {
    ll center = (n + 1) / 2;
    return center - x;
}

vector<int> make_table(ll n) {
    int t = (n + 1) / 2 % 3;
    if (t == 0) {
        return {3, 2, 1};
    } else if (t == 1) {
        return {1, 3, 2};
    } else {
        return {2, 1, 3};
    }
}

int main() {
    ll n;
    int k;
    cin >> n >> k;

    rep(_, k) {
        ll x, y;
        cin >> x >> y;
        x = conv_left_up(n, x);
        y = conv_left_up(n, y);

        x = conv_from_center(n, x);
        y = conv_from_center(n, y);

//        cout << x << ' ' << y << endl;

        ll distance = max(x, y);
        vector<int> table = make_table(n);
        cout << table[distance % 3] << endl;

    }

}