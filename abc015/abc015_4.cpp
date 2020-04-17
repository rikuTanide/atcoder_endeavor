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

struct ScreenShoot {
    int width, value;
};

int main() {
    int w, n, k;
    cin >> w >> n >> k;

    vector<ScreenShoot> screenShoots(n);
    rep(i, n) cin >> screenShoots[i].width >> screenShoots[i].value;

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(w + 1, -1)));
    dp[0][0][0] = 0;

    auto set = [&](int i, int j, int x, int value) {
        if (x > w) return;
        if (dp[i][j][x] == -1) {
            dp[i][j][x] = value;
            return;
        }
        cmax(dp[i][j][x], value);
    };

    rep(i, n) rep(j, n) rep(x, w) {
                if (dp[i][j][x] == -1) continue;
                int width = screenShoots[i].width;
                int value = screenShoots[i].value;

                set(i + 1, j + 1, x + width, dp[i][j][x] + value);
                set(i + 1, j, x, dp[i][j][x]);
            }

    int ans = 0;
    rep(i, n + 1) rep(j, k + 1) rep(x, w + 1) {
                cmax(ans, dp[i][j][x]);
            }
    cout << ans << endl;


}

