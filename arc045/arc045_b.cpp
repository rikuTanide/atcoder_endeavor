#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<int> &o) {
    ll a;
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

struct SegmentTree {
    ll N, dat[4 * 1000];

    SegmentTree() {}

    SegmentTree(ll n) {
        N = 1;
        while (N < n) N *= 2;
        for (ll i = 0; i < 2 * N - 1; i++)
            dat[i] = INF;
    }

    // update k th element
    void update(ll k, ll a) {
        k += N - 1; // leaf
        dat[k] = a;
        while (k > 0) {
            k = (k - 1) / 2;
            dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }

    // min [a, b)
    ll query(ll a, ll b) { return query(a, b, 0, 0, N); }

    ll query(ll a, ll b, ll k, ll l, ll r) {
        if (r <= a or b <= l) return INF;
        if (a <= l and r <= b) return dat[k];
        ll m = (l + r) / 2;
        return min(query(a, b, k * 2 + 1, l, m), query(a, b, k * 2 + 2, m, r));
    }
};


int main() {
    int n, m;
    cin >> n >> m;

    vector<P> range(m);
    rep(i, m) cin >> range[i].first >> range[i].second;
    rep(i, m) range[i].first--;
    rep(i, m) range[i].second--;

    vector<int> imos(n + 1, 0);
    for (P p : range) {
        imos[p.first]++;
        imos[p.second + 1]--;
    }
    rep(i, n) {
        imos[i + 1] += imos[i];
    }
    SegmentTree segmentTree(n);

    rep(i, n) segmentTree.update(i, imos[i]);

    vector<int> ans;
    rep  (i, m) {
        P p = range[i];
        if (segmentTree.query(p.first, p.second + 1) >= 2) {
            ans.push_back(i);
        }
    }

    cout << ans.size() << endl;
    for (int i : ans) cout << i + 1 << endl;

}
