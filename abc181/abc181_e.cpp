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

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
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
    int n, m;
    cin >> n >> m;


    vector<ll> students(n), transforms(m);
    rep(i, n) cin >> students[i];
    rep(i, m) cin >> transforms[i];

    sort(students.begin(), students.end());

//    sort(transforms.begin(), transforms.end());

    CumulativeSum gsum(n), kisum(n);
    rep(i, n) {
        if (i % 2 == 0) {
            if (i != n - 1) gsum.set(i, students[i + 1] - students[i]);
            if (i != 0) kisum.set(i, students[i] - students[i - 1]);
        }
    }
    gsum.build();
    kisum.build();
    ll ans = INF;
    for (ll t : transforms) {

        if (t <= students.front()) {
            ll r = kisum.getSectionSum(1, n);
            ll l = students.front() - t;
            ll now = r + l;
            cmin(ans, now);
        } else {
            auto it = upper_bound(students.begin(), students.end(), t);
            int left = distance(students.begin(), it);
            if (left % 2 == 1) {
                ll l = gsum.getSum(left - 2);
                ll c = t - students[left - 1];
                ll r = kisum.getSectionSum(left, n);
                ll now = l + c + r;
                cmin(ans, now);
//            cout << now << endl;
            } else {
                ll l = gsum.getSum(left);
                ll c = students[left] - t;
                ll r = kisum.getSectionSum(left + 1, n);
                ll now = l + c + r;
                cmin(ans, now);
//            cout << now << endl;
            }
        }
    }
    cout << ans << endl;

}
