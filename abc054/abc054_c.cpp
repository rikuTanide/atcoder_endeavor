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
//const ll INF = 10e15;
const ll MINF = -10e10;
const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("~/Downloads/02.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;

// https://kamino.hatenablog.com/entry/cpp-permutation-combination
void foreach_permutation(int n, std::function<void(vector<int>)> f) {
    vector<int> indexes(n);
    for (int i = 0; i < n; i++) indexes[i] = i;
    do {
        f(indexes);
    } while (std::next_permutation(indexes.begin(), indexes.end()));
}


int main() {

    int n, m;
    cin >> n >> m;

    vector<vector<bool>> routes(n, vector<bool>(n, false));

    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        routes[a][b] = true;
        routes[b][a] = true;
    }


    int ans = 0;
    foreach_permutation(n - 1, [&](vector<int> indexes) {
        vector<int> route(n);
        route[0] = 0;
        for (int k = 0; k < n - 1; k++) {
            route[k + 1] = indexes[k] + 1;
        }

        for (int k = 0; k < n - 1; k++) {
            int from = route[k];
            int to = route[k + 1];
            if (!routes[from][to]) {
                return;
            }
        }
        ans++;

    });

    cout << ans << endl;

}