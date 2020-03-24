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


int main() {
    int n, c;
    cin >> n >> c;

    vector<vector<int>> costs(c, vector<int>(c));
    rep(i, c) rep(j, c) cin >> costs[i][j];

    vector<vector<int>> grid(n, vector<int>(n));
    rep(i, n) rep(j, n) cin >> grid[i][j];
    rep(i, n) rep(j, n) grid[i][j]--;

    vector<vector<int>> use(c, vector<int>(3));

    rep(i, n) {
        rep(j, n) {
            int p = (i + j) % 3;
            int ci = grid[i][j];
            use[ci][p]++;
        }
    }

    auto check = [&](int d, int e, int f) {
        ll ans = 0;
        for (int i = 0; i < c; i++) {
            ll now = use[i][0] * costs[i][d];
            ans += now;
        }
        for (int i = 0; i < c; i++) {
            ll now = use[i][1] * costs[i][e];
            ans += now;
        }
        for (int i = 0; i < c; i++) {
            ll now = use[i][2] * costs[i][f];
            ans += now;
        }
        return ans;
    };

    ll ans = INF;

    for (int d = 0; d < c; d++) {
        for (int e = 0; e < c; e++) {
            for (int f = 0; f < c; f++) {
                if (d == e) continue;
                if (e == f) continue;
                if (f == d) continue;
                ll now = check(d, e, f);
                cmin(ans, now);
            }
        }
    }

    cout << ans << endl;
}



