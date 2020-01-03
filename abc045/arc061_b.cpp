#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<char> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;

int main() {


    ll h, w;
    int n;
    cin >> h >> w >> n;
    map<ll, map<ll, bool>> m;
    map<int, ll> ans;

    set<ll> check_ys;

    rep(i, n) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;

        m[a][b] = true;
        check_ys.insert(a - 1);
        check_ys.insert(a);
        check_ys.insert(a + 1);

    }
    check_ys.erase(-1);
    check_ys.erase(0);
    check_ys.erase(h - 1);
    check_ys.erase(h);

    for (ll check_y : check_ys) {
        set<ll> check_xs;

        for (int i = 0; i < 3; i++) {
            for (auto &&e : m[check_y - 1 + i]) {
                ll x = e.first;
                check_xs.insert(x - 1);
                check_xs.insert(x);
                check_xs.insert(x + 1);
            }
        }
        check_xs.erase(-1);
        check_xs.erase(0);
        check_xs.erase(w - 1);
        check_xs.erase(w);

        for (ll check_x : check_xs) {

            int black = 0;
            rep(x, 3)rep(y, 3) {
                    ll px = check_x - 1 + x;
                    ll py = check_y - 1 + y;
                    if (m.find(py) == m.end()) continue;
                    if (m[py].find(px) == m[py].end())continue;
                    if (m[py][px]) black++;
                }
            ans[black]++;

        }

    }


    ans[0] = (h - 2) * (w - 2);
    for (auto e : ans) {
        if (e.first == 0) continue;
        ans[0] -= e.second;
    }


    for (int i = 0; i <= 9; i++) {
        cout << ans[i] << endl;
    }

    cout << endl;


}