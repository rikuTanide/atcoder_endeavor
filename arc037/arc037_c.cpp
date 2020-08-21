#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
const ll INF = LONG_LONG_MAX;
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

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

ll f(ll a, vector<ll> &bs, ll mid) {
    if (bs[0] * a > mid) return 0;
    if (bs.back() * a <= mid) return bs.size();

    int floor = 0, ceil = bs.size() - 1;
    while (floor + 1 < ceil) {
        int i = (floor + ceil) / 2;
        ll b = bs[i];
        bool ok = b * a <= mid;
        if (ok) floor = i;
        else ceil = i;
    }
    return ceil;
}

ll check(vector<ll> &as, vector<ll> &bs, ll mid) {
    ll ans = 0;
    for (ll a : as) {
        ll now = f(a, bs, mid);
        ans += now;
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<ll> as(n), bs(n);
    rep(i, n) cin >> as[i];
    rep(i, n) cin >> bs[i];

    sort(as.begin(), as.end());
    sort(bs.begin(), bs.end());

    ll floor = 0, ceil = INF;
    while (floor + 1 < ceil) {
        ll mid = (floor + ceil) / 2;
        ll count = check(as, bs, mid);
        bool ok = count >= k;
        if (ok) ceil = mid;
        else floor = mid;
    }
    cout << ceil << endl;
}
