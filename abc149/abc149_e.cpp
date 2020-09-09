#include <bits/stdc++.h>
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

class CumulativeSum {
    vector<ll> numbers;
    vector<ll> sums;

public:
    CumulativeSum(int n) {
        numbers.resize(n);
        sums.resize(n);
    }

    void set(int i, ll value) {
        numbers[i] = value;
    }

    ll getSum(int i) {
        if (i == -1) return 0;
        if (i == sums.size()) return sums.back();
        return sums[i];
    }

    ll getSectionSum(int start, int end) {
        return getSum(end) - getSum(start - 1);
    }

    void build() {
        for (int i = 0; i < numbers.size(); i++) {
            sums[i] = getSum(i - 1) + numbers[i];
        }
    }

};

int main() {
    int n;
    ll m;
    cin >> n >> m;

    vector<ll> v(n);
    rep(i, n) cin >> v[i];

    sort(v.begin(), v.end());

    ll floor = 0, ceil = INF;
    auto check = [&](ll mid) -> bool {
        ll p = 0;
        for (ll b : v) {
            ll k = mid - b;
            auto it = lower_bound(v.begin(), v.end(), k);
            ll c = distance(it, v.end());
            p += c;
        }
        return p <= m;
    };

    while (floor + 1 < ceil) {
        ll mid = (floor + ceil) / 2;
        bool ok = check(mid);
        if (ok) ceil = mid;
        else floor = mid;
    }

    ll over_c = [&](ll mid) -> ll {
        ll p = 0;
        for (ll b : v) {
            ll k = mid - b;
            auto it = lower_bound(v.begin(), v.end(), k);
            ll c = distance(it, v.end());
            p += c;
        }
        return p;
    }(ceil);


    ll rem = m - over_c;

    ll over_h = [&](ll mid) -> ll {

        CumulativeSum cs(n);
        rep(i, n) cs.set(i, v[i]);
        cs.build();

        ll h = 0;
        for (ll b : v) {
            ll k = mid - b;
            auto it = lower_bound(v.begin(), v.end(), k);
            int c = distance(it, v.end());
            ll now = cs.getSectionSum(n - c, n) + (b * c);
            h += now;
        }
        return h;
    }(ceil);

    ll ans = over_h + (rem * floor);

    cout << ans << endl;
}
