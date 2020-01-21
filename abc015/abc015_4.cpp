#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX / 100;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;

struct ScreenShoot {
    int width, priority;
};

int main() {
    int w;
    cin >> w;
    int n, k;
    cin >> n >> k;

    vector<ScreenShoot> screenShoots(n);

    rep(i, n) {
        int a, b;
        cin >> a >> b;
        ScreenShoot ss = {a, b};
        screenShoots[i] = ss;
    }

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(100 * k + 1, -1)));

    auto get = [&](int maimemade, int k_mai, int width) {
        if (k_mai == 0 && width == 0) return 0;
        if (maimemade < 0 || k_mai < 0 || width < 0) return -1;
        return dp[maimemade][k_mai][width];
    };

    auto set = [&](int maimemade, int k_mai, int width, int priority) {
        cmax(dp[maimemade][k_mai][width], priority);
    };

    for (int n_maimemade = 0; n_maimemade < n; n_maimemade++) {
        int width = screenShoots[n_maimemade].width;
        int priority = screenShoots[n_maimemade].priority;

        for (int k_mai = 0; k_mai <= k; k_mai++) {
            // 置く
            for (int w_v = 0; w_v <= 100 * k; w_v++) {
                int before = get(n_maimemade - 1, k_mai - 1, w_v - width);
                if (before == -1) continue;
                set(n_maimemade, k_mai, w_v, before + priority);
            }
            // 置かない
            for (int w_v = 0; w_v <= 100 * k; w_v++) {
                int before = get(n_maimemade - 1, k_mai, w_v);
                if (before == -1) continue;
                set(n_maimemade, k_mai, w_v, before);
            }
        }
    }
    int ans = 0;
    for (int k_mai = 0; k_mai <= k; k_mai++) {
        for (int weight = 0; weight <= min(w, 100 * k); weight++) {
            cmax(ans, dp.back()[k_mai][weight]);
        }
    }

    cout << ans << endl;

}

// dp[枚目までを使って][枚数][横幅] = 重要度