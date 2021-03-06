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

int main() {
    // 愚直解を書く
    // 自分の左が自分より小さければノーカンを検証
    // 移動のたびに出し入れ

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    rep(i, n) cin >> v[i];
    set<vector<int>> s;


    auto is_first = [&]() -> bool {
        vector<int> u = v;
        sort(u.begin(), u.begin() + k);
        return u != v;
    };

    int ans = 1;
//    if (is_first()) ans++;

    set<int> used;
    rep(i, k) used.insert(v[i]);

    rep(i, n - k + 1) {
        if (i == 0) continue;

        int next_in = v[i + k - 1];
        int next_out = v[i - 1];

        bool is_left_min = [&]() -> bool {
            auto it = used.begin();
            return *it == next_out;
        }();
        bool is_right_max = [&]() -> bool {
            auto it = used.end();
            it--;
            return *it < next_in;
        }();

        if ((!is_left_min) || (!is_right_max))ans++;

        used.insert(next_in);
        used.erase(used.find(next_out));
    }

    vector<int> dp(n, 1);
    rep(i, n) {
        if (i == 0) continue;
        if (v[i - 1] < v[i])dp[i] = dp[i - 1] + 1;
    }

    int uc = count(dp.begin(), dp.end(), k);
    if (uc >= 2) {
        ans -= (uc - 1);
    }


    cout << ans << endl;
}
