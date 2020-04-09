#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

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

int main() {
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<ll> reds(a), blues(b), whites(c);
    rep(i, a) cin >> reds[i];
    rep(i, b) cin >> blues[i];
    rep(i, c) cin >> whites[i];

    sort(reds.rbegin(), reds.rend());
    sort(blues.rbegin(), blues.rend());
    sort(whites.rbegin(), whites.rend());
    vector<ll> eats;
    rep(i, x) eats.push_back(reds[i]);
    rep(i, y) eats.push_back(blues[i]);
    for (ll l : whites) eats.push_back(l);
    sort(eats.rbegin(), eats.rend());
    ll ans = accumulate(eats.begin(), eats.begin() + x + y, 0ll);
    cout << ans << endl;
}
