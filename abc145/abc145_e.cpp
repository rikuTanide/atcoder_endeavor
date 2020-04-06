#include <bits/stdc++.h>
#include <cmath>

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

#include <iostream>
#include <vector>

using namespace std;

struct Food {
    ll time, good;
};

vector<vector<ll>> knapsack(int n, ll t, vector<Food> &foods) {
    vector<vector<ll>> dp(n + 1, vector<ll>(t + 1, -1));
    dp[0][0] = 0;

    auto set = [&](int i, ll j, ll value) {
        if (i > n) return;
        if (j > t) return;
        if (dp[i][j] == -1) dp[i][j] = value;
        else
            cmax(dp[i][j], value);
    };

    rep(i, n) {
        rep(j, t + 1) {
            if (dp[i][j] == -1) continue;
            set(i + 1, j, dp[i][j]);
            set(i + 1, j + foods[i].time, dp[i][j] + foods[i].good);
        }
    }


    rep(i, n + 1) {
        rep(j, t + 1) {
            if (j == 0) continue;
            cmax(dp[i][j], dp[i][j - 1]);
        }
    }
    return dp;
}

vector<vector<ll>> knapsack2(int n, ll t, vector<Food> foods) {
    reverse(foods.begin(), foods.end());
    vector<vector<ll>> ans = knapsack(n, t, foods);
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    int n;
    ll t;
    cin >> n >> t;

    vector<Food> foods(n);
    rep(i, n)cin >> foods[i].time >> foods[i].good;

    vector<vector<ll>> k1 = knapsack(n, t - 1, foods);
    vector<vector<ll>> k2 = knapsack2(n, t - 1, foods);

    ll ans = 0;
    rep(i, n) {
        rep(t1, t) {
            ll t2 = t - t1 - 1;
            assert(t1 + t2 + 1 == t);

            ll left = k1[i][t1];
            ll right = k2[i + 1][t2];
            ll g = foods[i].good;
            ll now = left + right + g;
            cmax(ans, now);
        }
    }
    cout << ans << endl;
}