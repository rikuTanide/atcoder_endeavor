#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
typedef pair<ll, ll> P;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<string> &o) {
    string a;
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


class Conv {
    ll cursor = 0;
    map<ll, ll> to_short; // <original, small >
    map<ll, ll> to_long; // <small, original>
    std::set<ll> tmp;


public:
    void set(ll original) {
        if (to_short.find(original) != to_short.end()) {
            return;
        }
        to_long[cursor] = original;
        to_short[original] = cursor;
        cursor++;
    }

    ll revert(ll after) {
        assert(to_long.find(after) != to_long.end());
        return to_long[after];
    }

    ll convert(ll original) {
        assert(to_short.find(original) != to_short.end());
        return to_short[original];
    }

    ll next() {
        return cursor;
    }

    // 前計算省略のため
    void cache(ll t) {
        tmp.insert(t);
    }

    void build() {
        for (ll t : tmp) {
            set(t);
        }
    }

};

int main() {
    ll n, a, b;
    cin >> n >> a >> b;

    if (a + b > n + 1) {
        cout << -1 << endl;
        ret();
    }
    if (a * b < n) {
        cout << -1 << endl;
        ret();
    }

    vector<vector<int>> boxes(a);
    rep(i, b) boxes[0].push_back(i);

    ll sub = n - b;
    if (sub > 0) {
        ll par = sub / (a - 1);
        ll md = sub % (a - 1);
        rep(i, sub) {
            if (md * (par + 1) >= i) {
                ll j = i / (par + 1);
                boxes[j + 1].push_back(b + i);
            } else {
                ll p = md * (par + 1);
                ll j = i - p;
                ll k = j / par;
                ll f = md + 1 + k;
                boxes[f].push_back(b + i);
            }
        }
    }
    rep(i, a) reverse(boxes[i].begin(), boxes[i].end());

    for (vector<int> &v: boxes) {
        for (int i : v) cout << i + 1 << ' ';
    }
    cout << endl;

}

