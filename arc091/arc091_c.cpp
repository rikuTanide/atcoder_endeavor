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
    rep(i, a * b) boxes[i / b].push_back(i);

    ll sub = a * b - n;

    int sub_a = 0;
    rep(i, sub) {
        boxes[sub_a].pop_back();
        if (boxes[sub_a].size() == 1) sub_a++;
    }

    for (vector<int> &v: boxes) {
        sort(v.rbegin(), v.rend());
    }

    Conv conv;
    for (vector<int> &v: boxes) {
        for (int i : v) {
            conv.cache(i);
        }
    }
    conv.build();

    for (vector<int> &v: boxes) {
        for (int i : v) {
            cout << conv.convert(i) + 1 << ' ';
        }
    }
    cout << endl;
}

