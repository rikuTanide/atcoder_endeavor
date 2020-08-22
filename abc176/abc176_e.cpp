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
    int h, w;
    cin >> h >> w;

    int m;
    cin >> m;
    vector<P> ps(m);
    rep(i, m) cin >> ps[i].first >> ps[i].second, ps[i].first--, ps[i].second--;
    vector<ll> hs(h), ws(w);
    for (P p : ps) {
        hs[p.first]++;
        ws[p.second]++;
    }

    map<ll, ll> hc, wc;

    for (ll y : hs) hc[y]++;
    for (ll x : ws) wc[x]++;

    map<ll, ll> count_count;

    for (auto he : hc) {
        for (auto xe : wc) {
            ll yc = he.first;
            ll xc = xe.first;
            ll key = yc + xc;
            ll value = he.second * xe.second;
            count_count[key] += value;
        }
    }


//    for (auto e : count_count) {
//        printf("%lld %lld\n", e.first, e.second);
//    }
//    cout << endl;

    for (P p : ps) {
        ll y = hs[p.first];
        ll x = ws[p.second];

        count_count[y + x]--;
        count_count[y + x - 1]++;

    }
    ll ans = 0;
    for (auto e : count_count) {
//        printf("%lld %lld\n", e.first, e.second);
        if (e.second == 0) continue;
        cmax(ans, e.first);
    }
    cout << ans << endl;
}
