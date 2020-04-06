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

void warshall_floyd(int n, vector<vector<ll>> &distances) {
    for (int k = 0; k < n; k++) {       // 経由する頂点
        for (int i = 0; i < n; i++) {    // 始点
            for (int j = 0; j < n; j++) {  // 終点
                if (distances[i][j] == INF && (distances[i][k] == INF || distances[k][j] == INF)) {
                    distances[i][j] = INF;
                } else {
                    distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j]);
                }
            }
        }
    }
}


int main() {
    int n;
    cin >> n;

    vector<vector<bool>> has_edges(n, vector<bool>(n));
    rep(i, n) rep(j, n) {
            char c;
            cin >> c;
            has_edges[i][j] = c == '1';
        }

    vector<vector<ll>> distance(n, vector<ll>(n, INF));
    rep(i, n) distance[i][i] = 0;
    rep(i, n)rep(j, n) if (has_edges[i][j]) distance[i][j] = true;

    warshall_floyd(n, distance);

    rep(i, n) {
        vector<set<int>> v(n);
        rep(j, n) {
            int d = distance[i][j];
            v[d].insert(j);
        }
        rep(j, n) {
            for (ll k : v[j]) {
                for (ll l : v[j]) {
                    if (k == l) continue;
                    if (has_edges[k][l]) {
                        cout << -1 << endl;
                        ret();
                    }
                }
            }
        }
    }

    ll ans = -1;
    rep(i, n)rep(j, n) cmax(ans, distance[i][j] + 1);
    cout << ans << endl;

}