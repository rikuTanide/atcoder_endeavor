#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<int> &o) {
    int a;
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

int main() {
    int n;
    cin >> n;
    vector<vector<ll>> cards(2, vector<ll>(n));
    rep(i, 2) rep(j, n) cin >> cards[i][j];

    vector<vector<ll>> dp(1 << n, vector<ll>(n, INF * 2));
    rep(i, n) dp[1 << i][i] = i;
    rep(mask, (1 << n) - 1) {
        rep(i, n) {
            bool b = mask & (1 << i);
            if (!b) continue;
            bool b2 = dp[mask][i] < INF;
            if (!b2) continue;

            int pc = __builtin_popcount(mask);
            int cur = cards[abs(i - pc - 1) % 2][i];
            rep(x, n) {
                bool b3 = (mask & (1 << x)) == 0;
                if (b3) {
                    int nex = cards[abs(x - pc) % 2][x];
                    int num = __builtin_popcount((mask ^ (0xfffff)) & ((1 << x) - 1));
                    if (nex >= cur) {
                        dp[mask | (1 << x)][x] = min(dp[mask | (1 << x)][x], dp[mask][i] + num);
                    }
                }
            }

        }
    }

    ll mi = INF;
    rep(i, n) cmin(mi, dp[(1 << n) - 1][i]);

    if (mi >= INF) {
        cout << -1 << endl;
    } else {
        cout << mi << endl;
    }


}
