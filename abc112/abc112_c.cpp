#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
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
//ifstream myfile("C:\\Users\\riku\\Downloads\\01.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;

int main() {

    int n;
    cin >> n;

    vector<vector<ll>> vecs = vector<vector<ll>>(n, vector<ll>(3));

    rep(i, n) {
        ll x, y;
        ll h;
        cin >> x >> y >> h;

        vecs[i][0] = x;
        vecs[i][1] = y;
        vecs[i][2] = h;

    }

    for (ll x = 0; x <= 100; x++) {
        for (ll y = 0; y <= 100; y++) {

            if (x == 100 && y == 100) {
                cout << ' ';
            }

            ll check = [&] {
                ll before = INF;
                ll border = INF;
                for (ll i = 0; i < n; i++) {
                    ll vx = vecs[i][0];
                    ll vy = vecs[i][1];
                    ll vh = vecs[i][2];
                    if (vh == 0) {
                        ll diff = abs(vx - x) + abs(vy - y);
                        // 頂点がx , yだったとすると、vx, vz地点の高さはph のはず
                        ll ph = diff + vh;
                        border = min(border, ph);
                    }
                }

                for (ll i = 0; i < n; i++) {
                    ll vx = vecs[i][0];
                    ll vy = vecs[i][1];
                    ll vh = vecs[i][2];

                    ll diff = abs(vx - x) + abs(vy - y);
                    // 頂点がx , yだったとすると、vx, vz地点の高さはph のはず
                    ll ph = diff + vh;
                    if (vh == 0) {
                        continue;
                    }

                    if (ph > border) {
                        return -1ll;
                    }

                    if (before == INF) {
                        before = ph;
                    } else {
                        if (before != ph) {
                            return -1ll;
                        }
                    }
                }
                return before;
            }();

            if (check != -1) {
                cout << x << ' ' << y << ' ' << check << endl;
                return 0;
            }
        }
    }

}

//55 80 79