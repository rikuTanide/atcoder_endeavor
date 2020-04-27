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


int main() {

    int n, m;
    cin >> n >> m;

    vector<string> terms(n);
    rep(i, n) cin >> terms[i];

    auto can_one = [&](int i) {
        vector<string> use_strs;
        rep(j, n) {
            if (!((i >> j) & 1))continue;
            use_strs.push_back(terms[j]);
        }


        vector<char> candidate(m, '*');
        for (string s : use_strs) {
            rep(j, m) {
                if (s[j] == '*') continue;
                candidate[j] = s[j];
            }
        }
        for (string s : use_strs) {
            rep(j, m) {
                if (s[j] == '*') continue;
                if (candidate[j] != s[j]) return false;
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
