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

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

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


int solve(int n, int l, int r,
          CumulativeSum &qc_sum,
          CumulativeSum &oc_sum,
          CumulativeSum &cc_sum,
          CumulativeSum &o_depth_sum,
          CumulativeSum &c_depth_sum) {

    int sz = r - l + 1;

    int
            qc = qc_sum.getSectionSum(l, r),
            oc = oc_sum.getSectionSum(l, r),
            cc = cc_sum.getSectionSum(l, r);


    int ma = sz / 2;
    int ob = ma - oc;
    int cb = ma - ob;

    // 切り替え地点を見つける
    int p = [&] {

        auto check = [&](int i) -> bool {
            int now = qc_sum.getSectionSum(l, i);
            return ob <= now;
        };

        if (check(l)) return l;
        if (!check(r)) return -1;

        int floor = l, ceil = r;
        while (floor + 1 < ceil) {
            int mid = (floor + ceil) / 2;
            bool b = check(mid);
            if(b) ceil = mid;
            else floor = mid;
        }
        return ceil;
    }();

    if (p == -1) return false;

    int l_sum = o_depth_sum.getSectionSum(l, p);
    int r_sum = c_depth_sum.getSectionSum(p + 1, r);

    if (l_sum + r_sum != 0) return false;

    int ph = o_depth_sum.getSectionSum(l, p);
    int l_high = o_depth_sum.getSectionSum(0, l - 1);

    int l_min = [&] {
        int ans = INT_MAX;
        for (int i = l; i <= p; i++) {
            int now = o_depth_sum.getSectionSum(0, i);
            cmin(ans, now);
        }
        return ans;
    }();

    int r_min = [&] {
        int ans = INT_MAX;
        for (int i = p + 1; i <= r; i++) {
            int now = c_depth_sum.getSectionSum(0, i);
            cmin(ans, now);
        }
        return ans;
    }();

    if (l_min < l_high) return false;
    if ((r_min - c_depth_sum.getSectionSum(0, p)) + ph < 0) return false;

    return true;

}

int main() {
    int n, q;
    string s;
    cin >> n >> s >> q;

//    assert(n <= 1000);

    CumulativeSum qc_sum(n), oc_sum(n), cc_sum(n), o_depth_sum(n), c_depth_sum(n);

    rep(i, n) if (s[i] == '?') qc_sum.set(i, 1);
    rep(i, n) if (s[i] == '(') oc_sum.set(i, 1);
    rep(i, n) if (s[i] == ')') cc_sum.set(i, 1);

    rep(i, n) o_depth_sum.set(i, (s[i] == '?' || s[i] == '(') ? 1 : -1);
    rep(i, n) c_depth_sum.set(i, (s[i] == '?' || s[i] == ')') ? -1 : 1);

    qc_sum.build();
    oc_sum.build();
    cc_sum.build();
    o_depth_sum.build();
    c_depth_sum.build();

    rep(_, q) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        bool b = solve(n, l, r, qc_sum, oc_sum, cc_sum, o_depth_sum, c_depth_sum);
        string ans = b ? "Yes" : "No";
        cout << ans << endl;
    }
}
