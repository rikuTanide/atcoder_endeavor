#include <bits/stdc++.h>

const double PI = 3.14159265358979323846;
using namespace std;
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

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
const int mod = 1000000007;
//const ll mod = 1e10;
typedef priority_queue<string, vector<string>, greater<string> > PQ_ASK;


bool check(int m, string &s, string &t) {
    rep(i, m) {
        if (s[i] == t[i]) continue;
        if (s[i] == '*') continue;
        if (t[i] == '*') continue;
        return false;
    }
    return true;
}

int main() {

    int n, m;
    cin >> n >> m;

    vector<string> terms(n);
    rep(i, n) cin >> terms[i];


    vector<vector<bool>> is_match(n, vector<bool>(n));
    rep(i, n) rep(j, n) is_match[i][j] = check(m, terms[i], terms[j]);

    auto can_one = [&](int i) {
        vector<int> use_strs;
        rep(j, n) {
            if (!((i >> j) & 1))continue;
            use_strs.push_back(j);
        }

        for (int x : use_strs) {
            for (int y : use_strs) {
                if (!is_match[x][y]) return false;
            }
        }

        return true;
    };

    vector<int> dp(1 << n, n);
    dp[0] = 0;
    for (int i = 1; i < (1 << n); i = i << 1) {
        dp[i] = 1;
    }

    auto min_chair = [&](int i) {

        vector<int> u;
        rep(j, n) if ((i >> j) & 1) u.push_back(j);
        int ans = n;
        for (int s = (i - 1) & i; s > 0; s = (s - 1) & i) {
            int t = i ^s;
            int now = dp[s] + dp[t];
            cmin(ans, now);
        }
        return ans;
    };


    rep(i, 1 << n) {
        if (__builtin_popcount(i) <= 1) continue;
        if (can_one(i)) dp[i] = 1;
        else dp[i] = min_chair(i);
    }

    cout << dp[(1 << n) - 1] << endl;

}
