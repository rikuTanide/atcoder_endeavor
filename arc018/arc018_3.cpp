#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
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

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

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

ll dis(ll a, ll b, ll c, ll d) {
    return abs(a - c) + abs(b - d);
}

ll check(int l, map<int, P> &mp, int n, int m) {
    vector<int> arr(m);
    rep(i, m)arr[i] = i;
    ll ans = INF;
    do {
        ll now = 0;
        rep(i, m) {
            int j = arr[i] + l * m;
            P from = mp[j];
            ll d = dis(from.first, from.second, l, i);
            now += d;
        }
        cmin(ans, now);
    } while (std::next_permutation(arr.begin(), arr.end()));
    return ans;
}

int main() {
    int n, m, x0, a, p;
    cin >> n >> m >> x0 >> a >> p;

    vector<int> scores(n * m);
    scores[0] = x0;
    rep(i, n * m) {
        if (i == 0) continue;
        scores[i] = (scores[i - 1] + a) % p;
    }

    Conv conv;
    rep(i, n * m) conv.cache(scores[i]);
    conv.build();

    rep(i, n * m) scores[i] = conv.convert(scores[i]);

    map<int, P> mp;
    rep(i, n * m) mp[scores[i]] = P(i / m, i % m);

    ll ans = 0;
    rep(i, n) {
        ll now = check(i, mp, n, m);
        ans += now;
    }


    cout << ans << endl;

}