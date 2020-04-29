#include <bits/stdc++.h>

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

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;


int main() {
    int h, w, k;
    cin >> h >> w >> k;

    int n;
    cin >> n;
    vector<P> ps(n);
    rep(i, n) cin >> ps[i].first >> ps[i].second, ps[i].first--, ps[i].second--;
    vector<int> hs(h), ws(w);
    for (P p : ps) {
        hs[p.first]++;
        ws[p.second]++;
    }

    int MAX = 100005;
    vector<int> hc(MAX), wc(MAX);

    for (int y : hs) hc[y]++;
    for (int x : ws) wc[x]++;

    ll sum = 0;
    rep(i, k + 1) {
        int y = i;
        int x = k - y;
        assert(y + x == k);

        ll now = hc[y] * wc[x];
        sum += now;
    }

    for (P p : ps) {
        int y = hs[p.first];
        int x = ws[p.second];
        if (y + x == k) sum--;
        else if (y + x == k + 1) sum++;
    }

    cout << sum << endl;

}
