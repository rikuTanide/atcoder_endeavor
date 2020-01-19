#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX / 100;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;

void warshall_floyd(ll n, vector<vector<ll>> &distances) {
    for (ll k = 0; k < n; k++) {       // 経由する頂点
        for (ll i = 0; i < n; i++) {    // 始点
            for (ll j = 0; j < n; j++) {  // 終点
                distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j]);
            }
        }
    }
}


ll check(ll k, vector<vector<char>> &field, ll h, ll w) {
    vector<vector<ll>> distances(h * w, vector<ll>(h * w, INF));

    auto to_id = [&](ll y, ll x) {
        return y * w + x;
    };

    rep(y, h)rep(x, w) {
            distances[to_id(y, x)][to_id(y, x)] = 0;
            vector<P> move = {P(1, 0), P(0, 1), P(-1, 0), P(0, -1)};
            for (P m : move) {
                ll ny = y + m.first;
                ll nx = x + m.second;

                if (ny < 0) continue;
                if (ny == h) continue;
                if (nx < 0) continue;
                if (nx == w) continue;

                char n_color = field[ny][nx];
                if (n_color == 'S') n_color = '.';
                if (n_color == 'G') n_color = '.';

                if (n_color == '.') {
                    distances[to_id(y, x)][to_id(ny, nx)] = 1;
                } else {
                    distances[to_id(y, x)][to_id(ny, nx)] = k;
                }
            }
        }

    warshall_floyd(h * w, distances);

    ll start;
    ll goal;
    rep(y, h)rep(x, w) {
            if (field[y][x] == 'S') start = to_id(y, x);
            if (field[y][x] == 'G') goal = to_id(y, x);
        }

    return distances[start][goal];

}

int main() {
    ll h, w;
    ll t;
    cin >> h >> w >> t;

    vector<vector<char>> field(h, vector<char>(w));
    rep(y, h)rep(x, w)cin >> field[y][x];

    ll ceil = INF / 100;
    ll floor = 1;

    while (floor + 1 < ceil) {
        ll mid = (floor + ceil) / 2;
        ll time = check(mid, field, h, w);

        if (time == t) {
            cout << mid << endl;
            return 0;
        }
        if (time > t) {
            ceil = mid;
        } else {
            floor = mid;
        }
    }

    cout << floor << endl;


}

