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

ll f(vector<P> &fs, int k, ll x) {
    if (k == 0) return 0;
    return f(fs, k - 1, x) + abs(x - fs[k - 1].first) + fs[k - 1].second;
}

struct Half {

    priority_queue<ll> left;
    PQ_ASK right;

    ll left_sum = 0, right_sum = 0;

    ll half() {
        if (left.empty()) return 0;
        return left.top();
    }

    void right_push(ll v) {

        right.push(v);
        right_sum += v;
        while (left.size() < right.size()) {

            left_sum += right.top();
            right_sum -= right.top();

            left.push(right.top());
            right.pop();
        }
    }

    void left_push(ll v) {
        left.push(v);
        left_sum += v;
        while (left.size() > right.size() + 1) {
            right_sum += left.top();
            left_sum -= left.top();
            right.push(left.top());
            left.pop();
        }
    }

    void push(ll v) {
        if (v >= half()) {
            right_push(v);
        } else {
            left_push(v);
        }

    }


    ll diffSum() {
        ll rdiffsum = right_sum - half() * right.size();
        ll ldiffsum = half() * left.size() - left_sum;
        return rdiffsum + ldiffsum;
    }

};

int main() {
    vector<P> fs;

    Half as;
    ll bsum = 0;

    int q;
    cin >> q;
    rep(_, q) {
        int method;
        cin >> method;
        if (method == 1) {
            ll a, b;
            cin >> a >> b;
            as.push(a);
            bsum += b;

        } else {
            ll t = as.half();
            ll k = as.diffSum();
            printf("%lld %lld\n", t, k + bsum);
        }
    }

}
