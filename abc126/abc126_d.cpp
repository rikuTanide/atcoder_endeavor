#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = 1001001001;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)

const int mod = 1e9 + 7;

int n;
vector<vector<P>> tos;
vector<int> rFroms;

void bfs(int target, int d) {
    if(rFroms[target] != -1) return;
    rFroms[target] = d;
    auto to = tos[target];
    for (auto t : to) {
        bfs(t.first, (d + t.second) % 2);
    }
}


int main() {
    cin >> n;

    tos = vector<vector<P>>(n);
    rFroms = vector<int>(n, -1);

    rep(i, n - 1) {
        int from, to, distance;
        cin >> from >> to >> distance;
        from--;
        to--;
        tos[from].emplace_back(to, distance % 2);
        tos[to].emplace_back(from, distance % 2);
    }


    bfs(0, 0);

    for (auto r : rFroms) {
        cout << r << endl;
    }

}

