#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep(i, n) for (ll i = 0; i < (n); ++i)
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
typedef priority_queue<string, vector<string>, greater<string> > PQ_ASK;

#include <iostream>
#include <vector>

using namespace std;

const int mod = 1000000007;


int main() {

    int n, x, y;
    cin >> n >> x >> y;

    x--;
    y--;


    vector<vector<ll>> distances(n, vector<ll>(n, INF));
    rep(i, n) distances[i][i] = 0;

    rep(i, n) {
        rep(j, n) {
            if (i >= j) continue;
            assert(i < j);
            if (j <= x) {
                distances[i][j] = j - i;
                distances[j][i] = j - i;
            } else if (y <= i) {
                distances[i][j] = j - i;
                distances[j][i] = j - i;
            } else if (i <= x && y <= j) {
                ll l = x - i;
                ll r = j - y;
                ll now = l + r + 1;
                distances[i][j] = now;
                distances[j][i] = now;
            } else if (i <= x && x <= j && j <= y) {
                ll now = INF;
                // 直線
                {
                    now = j - i;
                }
                // 経由
                {
                    ll r = y - j;
                    ll l = x - i;
                    ll n2 = r + l + 1;
                    cmin(now, n2);
                }
                distances[i][j] = now;
                distances[j][i] = now;
            } else if (x <= i && i <= y && y <= j) {
                ll now = INF;
                // 直線
                {
                    now = j - i;
                }
                // 経由
                {
                    ll l = i - x;
                    ll r = j - y;
                    ll n2 = l + r + 1;
                    cmin(now, n2);
                }
                distances[i][j] = now;
                distances[j][i] = now;
            } else if (x <= i && j <= y) {
                ll now = INF;
                // 直線
                {
                    now = j - i;
                }
                {
                    ll l1 = i - x;
                    ll l2 = y - j;
                    ll n2 = l1 + l2 + 1;
                    cmin(now, n2);
                }
                distances[i][j] = now;
                distances[j][i] = now;
            } else {
                __throw_runtime_error("konai");
            }
        }
    }
    vector<ll> ans(n);
    rep(i, n) rep(j, n) ans[distances[i][j]]++;

    rep(i, n) {
        if (i == 0) continue;
        cout << ans[i] / 2 << endl;
    }
}
