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

int main() {
    vector<P> fs;

    vector<ll> as;
    ll bsum = 0;

    int q;
    cin >> q;
    rep(_, q) {
        int method;
        cin >> method;
        if (method == 1) {
            ll a, b;
            cin >> a >> b;
            as.push_back(a);
            bsum += b;

        } else {

            if (as.empty()) {
                cout << "0 0\n" << endl;
                continue;
            }

            sort(as.begin(), as.end());
            ll t = as[(as.size() - 1) / 2];
            ll k = 0;
            for (ll l : as) k += abs(t - l);
            printf("%lld %lld\n", t, k + bsum);
        }
    }

}
