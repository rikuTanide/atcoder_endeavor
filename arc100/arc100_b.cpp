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

P split(int l, int r, CumulativeSum &cs) {
    int floor = l + 1, ceil = r;

    while (floor + 1 < ceil) {
        int mid = (floor + ceil) / 2;
        ll l_sum = cs.getSectionSum(l, mid - 1);
        ll r_sum = cs.getSectionSum(mid, r - 1);
        if (l_sum > r_sum) ceil = mid;
        else floor = mid;
    }

    ll diff = INF;
    for (int mid = max(floor - 5, l + 1); mid < min(ceil + 5, r); mid++) {
        ll l_sum = cs.getSectionSum(l, mid - 1);
        ll r_sum = cs.getSectionSum(mid, r - 1);
        ll now_diff = abs(l_sum - r_sum);
        cmin(diff, now_diff);
    }

    for (int mid = max(floor - 5, l + 1); mid < min(ceil + 5, r); mid++) {
        ll l_sum = cs.getSectionSum(l, mid - 1);
        ll r_sum = cs.getSectionSum(mid, r - 1);
        ll now_diff = abs(l_sum - r_sum);
        if(now_diff == diff) return P(l_sum, r_sum);
    }
    __throw_runtime_error("konai");
}

ll solve(int n, int i, CumulativeSum &cs) {
    P bc = split(0, i, cs);
    P de = split(i, n, cs);

    vector<ll> tmp = {bc.first, bc.second, de.first, de.second};
    sort(tmp.begin(), tmp.end());
    return tmp.back() - tmp.front();
}

int main() {
    int n;
    cin >> n;
    vector<ll> v(n);
    rep(i, n) cin >> v[i];

    CumulativeSum cs(n);
    rep(i, n) cs.set(i, v[i]);
    cs.build();

    ll ans = INF;
    for (int i = 2; i <= n - 2; i++) {
        ll now = solve(n, i, cs);
        cmin(ans, now);
    }
    cout << ans << endl;


}
