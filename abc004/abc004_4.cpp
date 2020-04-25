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

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

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

int main() {
    int r, g, b;
    cin >> r >> g >> b;
    int all = r + g + b;
    map<int, vector<ll>> dp;
    for (int i = -400; i <= 400; i++) {
        dp[i] = vector<ll>(all + 1, INF);
    }

    auto next_marble = [&](int j) {
        if (j <= r) return 'R';
        if (j <= (r + g)) return 'G';
        if (j <= (r + g + b)) return 'B';
        return ' ';
    };

    auto get_from = [&](char c) {
        if (c == 'R') return -100;
        if (c == 'G') return 0;
        if (c == 'B') return 100;
        __throw_runtime_error("konai");
    };

    auto calc_cost = [&](int i, char c) {
        int from = get_from(c);
        return abs(i - from);
    };

    dp[-400][0] = 0;
    for (int i = -400; i < 400; i++) {
        rep(j, all + 1) {
            cmin(dp[i + 1][j], dp[i][j]);
            char c = next_marble(j + 1);
            if (c == ' ') continue;
            if (j == all) continue;
            ll cost = calc_cost(i + 1, c);
            cmin(dp[i + 1][j + 1], dp[i][j] + cost);
        }
    }

    cout << dp[400][all] << endl;

}

