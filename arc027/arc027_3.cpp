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

struct Topping {
    ll ticket, happiness;
};

std::istream &operator>>(std::istream &in, Topping &o) {
    cin >> o.ticket >> o.happiness;
    return in;
}


int main() {
    int x, y, n;
    cin >> x >> y >> n;

    vector<Topping> toppings(n);
    rep(i, n) cin >> toppings[i];

    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(n + 1, vector<ll>(x + y + 1, -1)));
    dp[0][0][0] = 0;

    auto set = [&](int i, int j, int ticket, ll happiness) {
        if (ticket > x + y) return;
        cmax(dp[i][j][ticket], happiness);
    };

    rep(i, n) {
        Topping t = toppings[i];
        rep(j, n) {
            rep(k, x + y + 1) {
                ll now = dp[i][j][k];
                if (now == -1)continue;
                set(i + 1, j + 1, k + t.ticket, now + t.happiness);
                set(i + 1, j, k, now);
            }
        }
    }

    ll ans = 0;
    rep(j, min(x, n) + 1) rep(k, x + y + 1) cmax(ans, dp.back()[j][k]);
    cout << ans << endl;

}