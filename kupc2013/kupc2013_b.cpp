#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;
//#include "atcoder/all"

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

bool equal(double a, double b) {
//    return fabs(a - b) < DBL_EPSILON;
    return fabs(a - b) < EPS;
}

template<class T>
std::istream &operator>>(std::istream &in, set<T> &o) {
    T a;
    in >> a;
    o.insert(a);
    return in;
}

template<class T>
std::istream &operator>>(std::istream &in, queue<T> &o) {
    ll a;
    in >> a;
    o.push(a);
    return in;
}

template<class T>
bool contain(set<T> &s, T a) { return s.find(a) != s.end(); }

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

vector<int> split(int n, int i, int x) {
    vector<int> ans;
    rep(_, n) {
        int f = i % (x + 1);
        ans.push_back(f);
        i /= (x + 1);
    }
    return ans;
}

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

struct Q {
    int l, r, s;
};

bool check(vector<int> &v, vector<Q> &qs) {
    CumulativeSum cs(v.size());
    rep(i, v.size()) cs.set(i, v[i]);
    cs.build();

    for (Q q : qs) {
        if (cs.getSectionSum(q.l, q.r) != q.s) return false;
    }
    return true;
}

int main() {
    int n, x, m;
    cin >> n >> x >> m;
    vector<Q> qs(m);
    for (Q &q: qs) cin >> q.l >> q.r >> q.s, q.l--, q.r--;


    int c = pow(x + 1, n);


    vector<int> ans;

    rep(i, c) {
        vector<int> v = split(n, i, x);
        if (check(v, qs)) {
            if (accumulate(ans.begin(), ans.end(), 0) < accumulate(v.begin(), v.end(), 0)) {
                ans = v;
            }
        }
    }

    if (ans.empty()) {
        cout << -1 << endl;
        ret();
    }

    for (int i : ans) cout << i << ' ';
    cout << endl;

}
