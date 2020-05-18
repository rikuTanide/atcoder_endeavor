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

    void calculate() {
        for (int i = 0; i < numbers.size(); i++) {
            sums[i] = getSum(i - 1) + numbers[i];
        }
    }

};


bool check(ll n, ll k, vector<ll> &numbers, ll target) {
    vector<ll> v(n);
    rep(i, n) v[i] = numbers[i] % target;
    sort(v.begin(), v.end());
    vector<ll> u(n);
    rep(i, n) u[i] = target - v[i];

    CumulativeSum csv(n), csu(n);
    rep(i, n) csv.set(i, v[i]);
    rep(i, n) csu.set(i, u[i]);
    csv.calculate();
    csu.calculate();

    rep(i, n - 1) {
        ll l = csv.getSectionSum(0, i);
        ll r = csu.getSectionSum(i + 1, n - 1);
        if (max(l, r) <= k) return true;
    }
    return false;
}

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> numbers(n);
    rep(i, n) cin >> numbers[i];

    ll all = accumulate(numbers.begin(), numbers.end(), 0ll);

    ll ans = 1;
    for (ll i = 1; i * i < all; i++) {
        if (all % i != 0) continue;
        if (check(n, k, numbers, i)) cmax(ans, i);
        if (check(n, k, numbers, all / i)) cmax(ans, all / i);
    }
    cout << ans << endl;
}
