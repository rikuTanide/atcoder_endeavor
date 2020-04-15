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
const int mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<int> colors(n);
    rep(i, n) cin >> colors[i];
    if (*min_element(colors.begin(), colors.end()) == *max_element(colors.begin(), colors.end())) {
        cout << -1 << endl;
        ret();
    }

    vector<int> dp(n, -1);
    dp[0] = 1;
    rep(i, n) {
        if (i == 0) continue;
        if (colors[i] == colors[i - 1]) dp[i] = dp[i - 1] + 1;
        else dp[i] = 1;
    }
    if (colors.front() == colors.back()) dp[0] = dp.back() + 1;
    rep(i, n) {
        if (i == 0) continue;
        if (colors[i] == colors[i - 1]) dp[i] = dp[i - 1] + 1;
        else dp[i] = 1;
    }

    int ma = *max_element(dp.begin(), dp.end());
    cout << (ma + 1) / 2 << endl;

}

