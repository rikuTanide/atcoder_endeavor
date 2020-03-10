#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<int, int> P;
const ll INF = 1e15;
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
    int n, m;
    cin >> n >> m;

    vector<vector<ll>> distances(n, vector<ll>(n, INT_MAX));
    rep(i, n) distances[i][i] = 0;
    rep(i, m) {
        int a, b;
        ll t;
        cin >> a >> b >> t;
        a--;
        b--;
        distances[a][b] = t;
        distances[b][a] = t;
    }

    warshall_floyd(n, distances);


    int ans = INT_MAX;
    rep(i, n) {
        int now = *max_element(distances[i].begin(), distances[i].end());
        cmin(ans, now);
    }
    cout << ans << endl;
}
