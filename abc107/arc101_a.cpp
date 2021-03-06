#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
//using namespace boost::multiprecision;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
const ll INF = 1e15;
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

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
const int mod = 1000000007;
//const ll mod = 1e10;
typedef priority_queue<string, vector<string>, greater<string> > PQ_ASK;

ll calc(ll a, ll b) {
    if (a <= 0 && b <= 0) {
        return max(abs(a), abs(b));
    }
    if (a >= 0 && b >= 0) {
        return max(abs(a), abs(b));
    }
    ll c1 = abs(b) + abs(b) + abs(a);
    ll c2 = abs(a) + abs(a) + abs(b);
    return min(c1, c2);
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> candles(n);
    rep(i, n) cin >> candles[i];

    ll ans = INF;
    for (int i = 0; i + k <= n; i++) {
        ll now = calc(candles[i], candles[i + k - 1]);
        cmin(ans, now);
    }
    cout << ans << endl;
}