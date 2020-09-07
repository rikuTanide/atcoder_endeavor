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

ll solve(int n, vector<ll> &v) {
    map<ll, ll> index;
    rep(i, n) index[v[i]] = i;

    ll ans = 0;

    set<int> used;

    for (int i = n; i > 0; i--) {
        int own_index = index[i];
        used.insert(own_index);
        bool has_left_lager = [&]() -> bool {
            auto it = used.lower_bound(own_index);
            if (it == used.begin()) return false;
            return true;
        }();
        int left_index = [&]() -> int {
            if (!has_left_lager) return -1;
            auto it = used.lower_bound(own_index);
            it--;
            return *it;
        }();
        bool has_right_lager = [&]() -> bool {
            auto it = used.lower_bound(own_index);
            it++;
            if (it == used.end()) return false;
            return true;
        }();
        if (!has_right_lager) continue;
        int right_lager_index = [&]() -> int {
            auto it = used.lower_bound(own_index);
            it++;
            return *it;
        }();
        bool has_right_right_lager = [&]() -> bool {
            auto it = used.lower_bound(right_lager_index);
            it++;
            if (it == used.end()) return false;
            return true;
        }();
        int right_right_index = [&]() -> int {
            if (!has_right_right_lager) return n;
            auto it = used.lower_bound(right_lager_index);
            it++;
            return *it;
        }();

        ll left_range = [&]() -> int {
            return own_index - left_index;
        }();
        ll right_range = [&]() -> int {
            return right_right_index - right_lager_index;
        }();

        ll now = left_range * right_range * i;

        ans += now;
    }

    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<ll> v(n);
    rep(i, n) cin >> v[i];

    ll a = solve(n, v);
    reverse(v.begin(), v.end());
    ll b = solve(n, v);


    ll ans = a + b;
    cout << ans << endl;
}
