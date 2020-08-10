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
    int n, m, k;
    cin >> n >> m >> k;

    CumulativeSum acs(n), bcs(m);
    rep(i, n) {
        ll a;
        cin >> a;
        acs.set(i, a);
    }
    rep(i, m) {
        ll b;
        cin >> b;
        bcs.set(i, b);
    }
    acs.build();
    bcs.build();

    int ans = 0;

    {
        auto it = upper_bound(bcs.sums.begin(), bcs.sums.end(), k);
        if (it == bcs.sums.begin()) {
            cout << 0 << endl;
            ret();
        }
        it--;
        int j = distance(bcs.sums.begin(), it) + 1;

        int now = j;
        ans = now;
    }

    rep(i, n) {
        ll t = k - acs.getSum(i);
        if (t < 0) continue;
        auto it = upper_bound(bcs.sums.begin(), bcs.sums.end(), t);
        if (it == bcs.sums.begin()) continue;
        it--;
        int j = distance(bcs.sums.begin(), it) + 1;

        int now = i + 1 + j;
        cmax(ans, now);
    }
    cout << ans << endl;
}
