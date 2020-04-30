#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
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

typedef pair<int, int> P;

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;


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


int main() {
    int n;
    ll t;
    cin >> n >> t;

    vector<Food> foods(n);
    rep(i, n)cin >> foods[i].time >> foods[i].good;

    sort(foods.rbegin(), foods.rend(), [](Food &f1, Food &f2){return f1.time < f2.time; });

    vector<vector<ll>> k1 = knapsack(n, t, foods);

    ll ans = 0;
    rep(i, n) {
        ll ma = *max_element(k1[i].begin(), k1[i].end());
        ll now = ma + foods[i].good;
        cmax(ans, now);
    }
    cout << ans <<  endl;
}
