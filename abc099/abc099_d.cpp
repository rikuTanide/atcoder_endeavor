#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = 10e10;
const ll MINF = -10e10;
//const int INF = INT_MAX;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)

typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;
const int mod = 1000000007;
//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

int main() {

// 普通に実装
// (i + j) % 3 = 0の色が0 ~ c

    int n, c;
    cin >> n >> c;


    vector<vector<int>> colors(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> iwakans(c, vector<int>(c, 0));

    rep(i, c) rep(j, c) {
            int d;
            cin >> d;
            iwakans[i][j] = d;
        }

    rep(x, n)rep(y, n) {
            int cc;
            cin >> cc;
            cc--;
            colors[x + 1][y + 1] = cc;
        }

    vector<vector<int>> ori(3, vector<int>(c, 0)); // %3=iのところにいるcolorの数
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= n; y++) {
            int m = (x + y) % 3;
            int color = colors[x][y];
            ori[m][color]++;
        }
    }


    ll ans = INF;
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < c; j++) {
            if (i == j) continue;

            for (int k = 0; k < c; k++) {
                if (i == k || j == k) continue;

//                printf("%d %d %d\n", i, j, k);

                ll now = 0;

                for (int color = 0; color < c; color++) {
                    {
                        int masu_su = ori[0][color];
                        int cost = iwakans[color][i];
                        now += masu_su * cost;
                    }
                    {
                        int masu_su = ori[1][color];
                        int cost = iwakans[color][j];
                        now += masu_su * cost;
                    }
                    {
                        int masu_su = ori[2][color];
                        int cost = iwakans[color][k];
                        now += masu_su * cost;
                    }
                }

                mins(ans, now);
            }
        }
    }

    cout << ans << endl;

}