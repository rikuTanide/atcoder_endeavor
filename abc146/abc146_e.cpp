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
    int n, k;
    cin >> n >> k;

    vector<ll> v(n);
    rep(i, n) cin >> v[i];
    rep(i, n) v[i]--;


    CumulativeSum cs(n);
    rep(i, n) cs.set(i, v[i]);
    cs.build();

    vector<ll> u(n);
    rep(i, n) u[i] = cs.getSum(i) % k;

    map<int, int> m;
    m[0] = 1;
    ll ans = 0;
    rep(i, n) {
        if (i == k - 1)m[0]--;
        if (i >= k) m[u[i - k]]--;

        ll t = u[i]; //(u[i] % k);
        ll now = m[t];

        ans += now;

        m[u[i]]++;

    }

//    rep(i, n) if (v[i] % k == 0) ans++;

    cout << ans << endl;
}
