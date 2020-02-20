#include <bits/stdc++.h>
#include <cmath>

//using namespace boost::multiprecision;
using namespace std;
typedef long long ll;
//typedef unsigned long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
typedef pair<int, int> P;
//typedef pair<ll, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX / 100;
//const ll INF = (1ll << 31) - 1;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
//typedef pair<int, int> P;
//typedef pair<double, double> P;
#define ret() return 0;

bool contain(set<char> &s, char a) { return s.find(a) != s.end(); }

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
const int mod = 1000000007;
//const ll mod = 1e10;
typedef priority_queue<long long, vector<long long>, greater<long long> > PQ_ASK;

ll gcd(ll x, ll y) {
    if (x > y) swap(x, y);
    ll m = 1;
    while (m != 0) {
        m = y % x;
        y = x;
        x = m;
    }
    return y;
}

ll lcm(ll x, ll y) {
    return x / gcd(x, y) * y;
}

ll k(ll x, ll y) {
    return x / y;
}

int main() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    if (c == 1 || d == 1) {
        cout << 0 << endl;
        ret();
    }

    ll g = lcm(c, d);

    ll kac = k(a - 1, c);
    ll kad = k(a - 1, d);
    ll kag = k(a - 1, g);

    ll kbc = k(b, c);
    ll kbd = k(b, d);
    ll kbg = k(b, g);

    ll aa = kac + kad - kag;
    ll ba = kbc + kbd - kbg;

    ll ans = b - a + 1 - (ba-aa);
    cout << ans << endl;

}

