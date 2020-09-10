#include <bits/stdc++.h>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

std::istream &operator>>(std::istream &in, set<ll> &o) {
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

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//const ll mod = 1e10;
//typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;

ll par2(ll l) {
    ll ans = 0;
    while (l % 2 == 0) {
        l /= 2;
        ans++;
    }
    return ans;
}

vector<ll> map_par2(vector<ll> v) {
    int n = v.size();
    vector<ll> u(n);
    rep(i, n) u[i] = par2(v[i]);
    return u;
}

int main() {
    int n;
    ll m;
    cin >> n >> m;
    vector<ll> v(n);
    rep(i, n) cin >> v[i];

    rep(i, n) v[i] /= 2;

    vector<ll> u = map_par2(v);

    if (*max_element(u.begin(), u.end()) != *min_element(u.begin(), u.end())) {
        cout << 0 << endl;
        ret();
    }

    ll p = u.front();

    vector<ll> t(n);
    rep(i, n) t[i] = v[i] / (1ll << p);

    ll k = t.front();
    rep(i, n) {
        k = k / __gcd(k, t[i]) * t[i];
    }

    ll f = m / (1ll << p) / k;
    ll ans = (f + 1) / 2;
    cout << ans << endl;

}