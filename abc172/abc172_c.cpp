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

public:
    vector<ll> sums;

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
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> as(n), bs(m);
    rep(i, n) cin >> as[i];
    rep(i, m) cin >> bs[i];

    int ans = 0;

    CumulativeSum as_sum(n), bs_sum(m);
    rep(i, n) as_sum.set(i, as[i]);
    rep(i, m) bs_sum.set(i, bs[i]);
    as_sum.build();
    bs_sum.build();

    rep(i, n + 1) {
        ll asum = i == 0 ? 0 : as_sum.getSum(i - 1);
        if (asum > k) continue;
        ll bmax = k - asum;


        auto it = upper_bound(bs_sum.sums.begin(), bs_sum.sums.end(), bmax);
        int bi = 0;
        if (it == bs_sum.sums.begin()) {

        } else {
            bi = distance(bs_sum.sums.begin(), it);
        }

        int now = i + bi;
        cmax(ans, now);
    }

    cout << ans << endl;
}
