#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;
//#include "atcoder/all"

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<int> &o) {
    int a;
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

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

vector<int> bfs(int city_count, vector<vector<int>> &edges) {
    vector<int> distances(city_count, INT_MAX);
    distances[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        int now_distance = distances[now];
        for (int next : edges[now]) {
            int next_distance = distances[next];
            if (next_distance > now_distance + 1) {
                distances[next] = now_distance + 1;
                q.push(next);
            }
        }
    }
    return distances;
}

int main() {
    int city_count, pandemic_term, pandemic_distance, target_day;
    cin >> city_count >> pandemic_term >> pandemic_distance >> target_day;

    vector<P> cities(city_count);
    for (P &p: cities)cin >> p.first >> p.second;

    vector<vector<int>> edges(city_count);

    auto is_nealy = [&](int i, int j) -> bool {
        ll w = cities[i].first - cities[j].first;
        ll h = cities[i].second - cities[j].second;

        ll ww = w * w;
        ll hh = h * h;

        return ww + hh <= pandemic_distance * pandemic_distance;
    };

    ll MAX = 1500;
    vector<vector<int>> matrix(MAX);
    for (P p:cities) matrix[p.first].push_back(p.second);
    rep(x, MAX) sort(matrix[x].begin(), matrix[x].end());

    map<int, map<int, int>> mp;
    rep(i, city_count) {
        P p = cities[i];
        mp[p.first][p.second] = i;
    }

    auto get = [&](int x, int y) -> int {
        assert(mp.find(x) != mp.end());
        assert(mp[x].find(y) != mp[x].end());
        return mp[x][y];
    };

    rep(i, city_count) {
        P p = cities[i];
        for (ll x = max<ll>(p.first - pandemic_distance, 0); x <= min(p.first + pandemic_distance, MAX - 1); x++) {
            for (auto it = lower_bound(matrix[x].begin(), matrix[x].end(), p.second - pandemic_distance);
                 it < upper_bound(matrix[x].begin(), matrix[x].end(), p.second + pandemic_distance);
                 it++) {
                int j = get(x, *it);
                if (is_nealy(i, j)) {
                    edges[i].push_back(j);
//                    cout << i << ' ' << j << endl;
//                    edges[j].push_back(i);
                }
            }
        }
    }

    vector<int> distances = bfs(city_count, edges);
    int ans = 0;
    for (int i : distances) {
        if (i > target_day) continue;
        if (target_day - pandemic_term >= i) continue;;
        ans++;
    }
    cout << ans << endl;
}
