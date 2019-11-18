#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
typedef pair<int, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = 1001001001;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)

const int mod = 1e9 + 7;

int n;
vector<vector<int>> tos;
set<int> not_visited;

void bfs(int target) {
    if (not_visited.find(target) == not_visited.end()) return;
    not_visited.erase(target);
    auto to = tos[target];
    for (auto t : to) {
        bfs(t);
    }
}


int main() {
    int m;
    cin >> n >> m;

    tos = vector<vector<int>>(n);

    rep(i, m) {
        int x, y, z;
        cin >> x >> y >> z;

        x--;
        y--;
        z--;

        tos[x].push_back(y);
//        tos[x].push_back(z);

        tos[y].push_back(x);
//        tos[y].push_back(z);

//        tos[z].push_back(x);
//        tos[z].push_back(y);

    }

    rep(i, n) {
        not_visited.insert(i);
    }

    int c = 0;
    while (!not_visited.empty()) {
        int i = *not_visited.begin();
        bfs(i);
        c++;
    }

    cout << c << endl;

}

