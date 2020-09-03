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
    int n, q;
    cin >> n >> q;

    vector<ll> v(n);
    rep(i, n) cin >> v[i];

    CumulativeSum cs(n), cs_even(n), cs_odd(n);
    rep(i, n) cs.set(i, v[i]);
    rep(i, n) if (i % 2 == 0) cs_even.set(i, v[i]);
    rep(i, n) if (i % 2 == 1) cs_odd.set(i, v[i]);

    cs.build();
    cs_even.build();
    cs_odd.build();

    map<ll, ll> m;

    auto get_l_score = [&](int r) -> ll {
        if (r == -1) return 0;
        if (r % 2 == 0) return cs_even.getSum(r);
        return cs_odd.getSum(r);
    };

    for (int i = 1; i * 2 < n; i++) {
        int b_r = n - 1;
        int b_l = b_r - i + 1;
        int a_r = b_l - 1;
        int a_l = a_r - i + 1;

        ll d = v[a_l - 1];
        ll u = v[a_r];

        ll x = (u + d) / 2 + 1;
//        printf("%d %d %d %d %lld\n", a_l, a_r, b_l, b_r, x);
//
        ll a_r_score = cs.getSectionSum(b_l, b_r);
        ll b_r_score = cs.getSectionSum(a_l, a_r);

        ll a_l_score = get_l_score(a_l - 1);

        ll score = a_r_score + a_l_score;

        m[x] = score;
    }

    m[0] = cs.getSectionSum(n / 2, n);
    m[INF] = get_l_score(n - 1);

    rep(_, q) {
        ll x;
        cin >> x;
        auto it = m.upper_bound(x);
        it--;
        cout << (*it).second << endl;

    }


}
