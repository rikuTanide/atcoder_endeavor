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

map<ll, int> factorize(ll n) {
    map<ll, int> res;

    for (ll i = 2; i * i <= n; i++) {
        if (n % i != 0) {
            continue;
        }
        res[i] = 0;
        while (n % i == 0) {
            n /= i;
            res[i]++;
        }
    }

    if (n != 1) res[n] = 1;
    return res;
}


int main() {
    int n;
    cin >> n;
    ll k;
    cin >> k;
    vector<ll> t(n);
    rep(i, n) cin >> t[i];

    auto check = [&](ll a) -> bool {
        vector<ll> u(n);
        rep(i, n) u[i] = t[i] % a;
        if (count(u.begin(), u.end(), 0) == n) return true;
        sort(u.rbegin(), u.rend());
        CumulativeSum cs(n);
        rep(i, n) cs.set(i, u[i]);
        cs.build();

        rep(i, n) {
            ll l = cs.getSum(i);
            ll r = cs.getSectionSum(i + 1, n);
            ll lr = (i + 1) * a - l;
            if (lr == r && lr <= k) return true;
        }
        return false;
    };

    ll sum = accumulate(t.begin(), t.end(), 0ll);
    ll ma = sum / n;

    vector<ll> candidate;

    for (ll a = 1; a * a <= sum; a++) {
        if (sum % a == 0) candidate.push_back(a), candidate.push_back(sum / a);
    }
    sort(candidate.rbegin(), candidate.rend());

    for (ll a : candidate) {
        if (sum % a != 0) continue;
        bool ok = check(a);
        if (ok) {
            cout << a << endl;
            ret();
        }
    }
}
