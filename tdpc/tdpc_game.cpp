#include <bits/stdc++.h>
//#include "atcoder/all"
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

template<class T>
bool contain(set<T> &s, T a) { return s.find(a) != s.end(); }

template<class T, class U>
bool contain(map<T, U> &s, T a) { return s.find(a) != s.end(); }


typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

map<P, ll> rec(vector<ll> &as, vector<ll> &bs, int n) {
    if (n == as.size() + bs.size()) {
        map<P, ll> memo;
        memo[P(0, 0)] = 0;
        return memo;
    }

    auto prev = rec(as, bs, n + 1);

    // 偶数・奇数から最大化したいか最小化したいか割り出す

    auto superior = [&](ll x, ll y) -> ll {
        if (n % 2 == 0) return max(x, y);
        return min(x, y);
    };

    auto choose = [&](P p, char t) -> ll {
        assert(t == 'a' || t == 'b');
        if (t == 'a') {
            P next(p.first - 1, p.second);
            assert(contain(prev, next));
            int target = p.first - 1;
            return prev[next] + (n % 2 == 0 ? as[target] : 0);
        } else {
            P next(p.first, p.second - 1);
            assert(contain(prev, next));
            int target = p.second - 1;
            return prev[next] + (n % 2 == 0 ? bs[target] : 0);
        }
    };

    // 取れる選択肢を列挙

    vector<P> methods;
    for (int a = 0; a <= (as.size() + bs.size()) - n; a++) {
        int b = as.size() + bs.size() - n - a;
        if (a > as.size()) continue;
        if (b > bs.size())continue;
        if (b < 0)continue;
        methods.push_back(P(a, b));
    }

    // 各選択肢でどっちがお得か判定
    map<P, ll> next;
    for (P p : methods) {
        if (p.first != 0 && p.second != 0) {
            ll x = choose(p, 'a');
            ll y = choose(p, 'b');
            next[p] = superior(x, y);
        } else if (p.first > 0) {
            next[p] = choose(p, 'a');
        } else {
            next[p] = choose(p, 'b');
        }

    }
    return next;

}

int main() {
    int a, b;
    cin >> a >> b;

    vector<ll> as(a), bs(b);
    rep(i, a)cin >> as[i];
    rep(i, b)cin >> bs[i];
    reverse(as.begin(), as.end());
    reverse(bs.begin(), bs.end());


    ll res = rec(as, bs, 0)[P(a, b)];
    cout << res << endl;


}