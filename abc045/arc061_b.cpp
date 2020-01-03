#include <bits/stdc++.h>
#include <cmath>

using namespace std;
//typedef long long ll;
typedef unsigned long long ll;

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
//    ifstream myfile("C:\\Users\\riku\\Downloads\\08.txt");


    ll h, w;
    int n;
    cin >> h >> w >> n;
//    myfile >> h >> w >> n;

    set<P> q;
    map<ll, map<ll, bool>> m;

    {
        vector<P> blacks(n);
        rep(i, n) {
            ll a, b;
            cin >> a >> b;
//            myfile >> a >> b;
            a--;
            b--;

            blacks[i].first = b;
            blacks[i].second = a;
        }

        for (P p : blacks) {
            m[p.first][p.second] = true;
        }

        for (P p: blacks) {
            rep(x, 3)
                rep(y, 3) {
                    ll px = p.first - 1 + x;
                    ll py = p.second - 1 + y;
                    if (px == -1 || px == w) continue;
                    if (px == 0 || px == w - 1) continue;
                    if (py == -1 || py == h) continue;
                    if (py == 0 || py == h - 1) continue;

                    P next(px, py);
                    q.insert(next);
                }
        }
    }

    map<int, ll> ans;
    for (P p : q) {
        int black = 0;
        rep(x, 3)
            rep(y, 3) {
                ll px = p.first - 1 + x;
                ll py = p.second - 1 + y;
                if (m[px][py]) black++;
            }
        ans[black]++;
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
