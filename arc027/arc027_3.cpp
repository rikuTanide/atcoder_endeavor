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

struct Topping {
    int cost;
    ll happiness;
};

std::istream &operator>>(std::istream &in, Topping &o) {
    in >> o.cost >> o.happiness;
    return in;
}

int main() {
    int x, y;
    cin >> x >> y;

    int n;
    cin >> n;

    vector<Topping> toppings(n);
    rep(i, n) cin >> toppings[i];
    const int MAX = 300 * 600 + 10;
    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(n + 1, vector<ll>(MAX + 400, 0)));

    auto get = [&](int i, int j, int k) -> ll {
        return dp[i][j][k];
    };

    auto set = [&](int i, int j, int k, ll value) {
        cmax(dp[i][j][k], value);
    };

    rep(i, n) {
        rep(j, n) {
            rep(k, MAX) {
                Topping t = toppings[i];
                ll prev_happy = get(i, j, k);
                set(i + 1, j + 1, k + t.cost, prev_happy + t.happiness);
                set(i + 1, j, k, prev_happy);
            }
        }
    }
    ll ans = 0;
    rep(j, min(n + 1, x + 1)) rep(k, x + y + 1) cmax(ans, dp[n][j][k]);
    cout << ans << endl;
}
