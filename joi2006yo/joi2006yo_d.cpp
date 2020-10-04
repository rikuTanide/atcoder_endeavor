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


//一番小さいコップを左に置くなら
// 二番目に小さいコップはいったん右に置く
// 三番目は左
// 5,6,7...を右に置くコストは6を左に置くコスト+2+6,7...の山を動かすコスト


struct Tray {
    vector<vector<int>> v;

    Tray() : v(3) {}

    void add(int tray, int num) {
        v[tray].push_back(num);
    }

    ll size() {
        return v[0].size() + v[1].size() + v[2].size();
    }

    Tray reverse() {
        Tray t;
        t.v[0] = this->v[2];
        t.v[1] = this->v[1];
        t.v[2] = this->v[0];
        return t;
    }

    bool has(int i, int value) {
        return find(v[i].begin(), v[i].end(), value) != v[i].end();
    }

    ll move(int k) {
        if (k == this->size()) return 0;
        return this->move(k + 1) * 3 + 2;
    }

};

/* 下から順番に
 * 一番左にそろえるか一番右にそろえる
 * 自分が一番左にいるなら自分の一個上を一番左にそろえるコスト
 * 自分が真ん中にいるなら自分の一個上を一番右にそろえるコスト＋自分の上の山を一回反対に動かすコスト
 * 自分が一番右にいるなら自分の一個上を左にそろえるコスト＋２＋山を二回反対に動かすコスト
 */

ll over(ll a, ll m) {
    if (a > m) return INF;
    return a;
}

ll solve(int mi, char target, Tray tray, ll ma) {
    if (mi == tray.size()) return 0;
    if (target == 'R') {
        ll ans = solve(mi, 'L', tray.reverse(), ma);
        return over(ans, ma);
    }
    if (tray.has(0, mi)) {
        ll ans = solve(mi + 1, 'L', tray, ma);
        return over(ans, ma);
    }
    if (tray.has(1, mi)) {
        ll s = solve(mi + 1, 'R', tray, ma);
        ll m = tray.move(mi + 1);
        ll ans = s + 1 + m;
        return over(ans, ma);
    }
    if (tray.has(2, mi)) {
        ll s = solve(mi + 1, 'L', tray, ma);
        ll m = tray.move(mi + 1);
        ll mm = m * 2;
        ll ans = s + 2 + mm;
        return over(ans, ma);
    }
    throw_with_nested("konai");
}

int main() {
    int n, m;
    cin >> n >> m;

    Tray tray;

    rep(t, 3) {
        int c;
        cin >> c;
        rep(_, c) {
            int i;
            cin >> i;
            i--;
            tray.add(t, i);
        }
    }

    ll l = solve(0, 'L', tray, m);
    ll r = solve(0, 'R', tray, m);
    ll ans = min(l, r);

    cout << (ans == INF ? -1 : ans) << endl;
}
