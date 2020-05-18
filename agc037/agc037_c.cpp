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


int main() {
    int n;
    cin >> n;
    vector<ll> as(n), bs(n);
    rep(i, n)cin >> as[i];
    rep(i, n) cin >> bs[i];

    priority_queue<P> q;
    rep(i, n) q.push(P(bs[i], i));

    auto a_get = [&](int i) {
        if (i == -1) return as.back();
        if (i == n) return as.front();
        return as[i];
    };

    auto b_get = [&](int i) {
        if (i == -1) return bs.back();
        if (i == n) return bs.front();
        return bs[i];
    };

    ll ans = 0;

    while (!q.empty()) {
        P p = q.top();
        q.pop();

        ll l = b_get(p.second - 1);
        ll c = b_get(p.second);
        ll ac = a_get(p.second);
        assert(p.first == c);
        ll r = b_get(p.second + 1);

        if (!(l + r <= c)) continue;
        if (!(ac < c)) continue;


        ll lr = l + r;
        ll diff = c - ac;
        ll nb = diff % lr;
        ll count = diff / lr;

        if (count == 0) break;
        ans += count;
        bs[p.second] = ac + nb;

        if (bs[p.second] != ac) {
            q.push(P(bs[p.second], p.second));
        }
    }

    if (as == bs) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }

}
