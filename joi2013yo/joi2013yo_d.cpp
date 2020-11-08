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

struct Fashion {
    int low, height, gaudy;
};

int main() {
    int d, n;
    cin >> d >> n;

    vector<ll> tmp(d);
    rep(i, d) cin >> tmp[i];

    vector<Fashion> fashions(n);
    for (Fashion &f : fashions) cin >> f.low >> f.height >> f.gaudy;


    vector<ll> prev(n);
    rep(k, d) {
        vector<ll> next(n);

        rep(i, n) {
            if (tmp[k] < fashions[i].low || fashions[i].height < tmp[k]) {
                next[i] = -INF;
                continue;
            }

            if(k == 0) continue;

            rep(j, n) {
                ll now = abs(fashions[i].gaudy - fashions[j].gaudy) + prev[j];
                cmax(next[i], now);
            }
        }

        prev = next;
    }

    ll ans = *max_element(prev.begin(), prev.end());
    cout << ans << endl;
}
