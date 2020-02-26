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

ll pow2(ll a, ll b) {
    ll res = a;
    for (ll i = 1; i < b; i++) {
        res *= a;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, INT_MIN);
    dp[0] = 0;

    set<int> c;
    for (int i = 1; pow2(6, i) <= n; i++) c.insert(pow2(6, i));
    for (int i = 1; pow2(9, i) <= n; i++) c.insert(pow2(9, i));

    auto set = [&](int i, int v) {
        if (i > n) return;
        else if (dp[i] < 0) dp[i] = v;
        else
            cmin(dp[i], v);
    };

    for (int i = 0; i <= n; i++) {
        if (dp[i] < 0) continue;

        for (int b : c) {
            set(i + b, dp[i] + 1);
        }

    }

    int ans = n;
    for (int i = 0; i <= n; i++) {
        int now = dp[i];
        if(now < 0) continue;
        now += (n - i);
        cmin(ans, now);
    }

    cout << ans << endl;

}
