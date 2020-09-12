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

ll calc_minus_count(vector<ll> minus, vector<ll> plus) {
    return minus.size() * plus.size();
}

ll calc_plus_count(vector<ll> minus, vector<ll> plus) {
    return minus.size() * (minus.size() - 1) / 2 + plus.size() * (plus.size() - 1) / 2;
}

ll calc_zero_count(vector<ll> minus, vector<ll> plus, vector<ll> zero) {
    return zero.size() * minus.size() + zero.size() * plus.size() + zero.size() * (zero.size() - 1) / 2;
}

ll solve_minus(vector<ll> minus, vector<ll> plus, ll k) {
    sort(minus.begin(), minus.end());
    sort(plus.begin(), plus.end());

    auto check = [&](ll x) -> bool {
        ll count = 0;
        for (ll m : minus) {
            if (m * plus.back() > x) continue;
            if (m * plus.front() <= x) {
                count += plus.size();
                continue;
            }
            ll floor = 0, ceil = plus.size();
            while (floor + 1 < ceil) {
                ll mid = (floor + ceil) / 2;
                ll p = plus[mid];
                ll mp = m * p;
                bool under = mp <= x;
                if (under) ceil = mid;
                else floor = mid;
            }
            ll now = plus.size() - ceil;
            count += now;

        }
        return count >= k;
    };

//    ll floor = -INF, ceil = 0;
    ll floor = -INF, ceil = 0;
    while (floor + 1 < ceil) {
        ll mid = (floor + ceil) / 2;
        bool ok = check(mid);
        if (ok) ceil = mid;
        else floor = mid;
    }

    return ceil;
}


ll solve_plus(vector<ll> minus, vector<ll> plus, ll k) {
    for (ll &m : minus) m = -m;
    sort(minus.begin(), minus.end());
    sort(plus.begin(), plus.end());

    auto counts = [&](ll x, vector<ll> &v) -> ll {
        int n = v.size();
        ll count = 0;
        rep(i, n - 1) {
            ll p1 = v[i];
            vector<ll> v2(v.begin() + i + 1, v.end());

            if (p1 * v2.front() > x) continue;
            if (p1 * v2.back() <= x) {
                count += v2.size();
                continue;
            }

            ll floor = 0, ceil = v2.size();
            while (floor + 1 < ceil) {
                ll mid = (floor + ceil) / 2;
                bool under = p1 * v2[mid] <= x;
                if (under)floor = mid;
                else ceil = mid;
            }
            count += (floor + 1);
        }
        return count ;
    };

    auto check = [&](ll x) -> bool {
        ll count = counts(x, minus) + counts(x, plus);
        return count >= k;
    };

//    ll floor = -INF, ceil = 0;
    ll floor = 0, ceil = INF;
    while (floor + 1 < ceil) {
        ll mid = (floor + ceil) / 2;
        bool ok = check(mid);
        if (ok) ceil = mid;
        else floor = mid;
    }

    return ceil;
}

int main() {
    ll n;
    ll k;
    cin >> n >> k;

    vector<ll> v(n);
    rep(i, n) cin >> v[i];

    vector<ll> minus, plus, zero;
    for (ll l : v) {
        if (l == 0) zero.push_back(l);
        else if (l > 0) plus.push_back(l);
        else minus.push_back(l);
    }

    ll mc = calc_minus_count(minus, plus);
    ll pc = calc_plus_count(minus, plus);
    ll zc = calc_zero_count(minus, plus, zero);

    assert(mc + pc + zc == n * (n - 1) / 2);

    if (mc < k && k <= mc + zc) {
        cout << 0 << endl;
        ret();
    }

    if (k <= mc) {
        ll ans = solve_minus(minus, plus, k);
        cout << ans << endl;
        ret();
    }

    k -= mc;
    k -= zc;

//    vector<ll> tmp;
//
//
//    for (int i = 0; i < plus.size(); i++) {
//        for (int j = i + 1; j < plus.size(); j++) {
//            tmp.push_back(plus[i] * plus[j]);
//        }
//    }
//
//    for (int i = 0; i < minus.size(); i++) {
//        for (int j = i + 1; j < minus.size(); j++) {
//            tmp.push_back(minus[i] * minus[j]);
//        }
//    }

//    sort(tmp.begin(), tmp.end());
//    cout << tmp[k - 1] << endl;

    ll ans = solve_plus(minus, plus, k);
    cout << ans << endl;
}
