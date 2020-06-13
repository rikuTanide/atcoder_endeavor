#include <bits/stdc++.h>

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

//const ll mod = 1e10;
typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;


class UnionFind {
public:
    // 親の番号を格納する。親だった場合-size
    vector<int> parents;

    UnionFind(int n) {
        parents = vector<int>(n, -1);
    }

    // aがどのグループに属しているか
    int root(int a) {
        if (parents[a] < 0) {
            return a;
        }
        return parents[a] = root(parents[a]);
    }

    int size(int a) {
        return -parents[root(a)];
    }

    // aとbをくっつける
    bool connect(int a, int b) {
        int ra = root(a);
        int rb = root(b);
        if (ra == rb) {
            return false;
        }
        // 大きいほうにA
        if (size(ra) < size(rb)) {
            swap(ra, rb);
        }
        parents[ra] += parents[rb];
        parents[rb] = ra;
        return true;
    }

};

bool is_2(int i, vector<vector<bool>> &edges) {
    int n = edges.size();
    vector<int> costs(n, -1);
    costs[i] = 0;

    queue<int> q;
    q.push(i);

    while (!q.empty()) {
        int from = q.front();
        q.pop();
        rep(to, n) {
            if (from == to) continue;
            else if (!edges[from][to]) continue;
            else if (costs[to] != -1) {
                int to_cost = costs[to];
                int from_cost = costs[from];

                if (to_cost == (from_cost ^ 1)) {
                    continue;
                } else {
                    return false;
                }
            } else {
                int from_cost = costs[from];
                int to_cost = from_cost ^1;
                costs[to] = to_cost;
                q.push(to);
            }
        }
    }
    return true;
}

P count_2(int i, vector<vector<bool>> &edges) {
    int n = edges.size();
    vector<int> costs(n, -1);
    costs[i] = 0;

    queue<int> q;
    q.push(i);

    while (!q.empty()) {
        int from = q.front();
        q.pop();
        rep(to, n) {
            if (from == to) continue;
            else if (!edges[from][to]) continue;
            else if (costs[to] != -1) continue;
            else {
                int from_cost = costs[from];
                int to_cost = from_cost ^1;
                costs[to] = to_cost;
                q.push(to);
            }
        }
    }

    int a = count(costs.begin(), costs.end(), 0);
    int b = count(costs.begin(), costs.end(), 1);

    return P(a, b);

}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<bool>> edges(n, vector<bool>(n, true));
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        edges[a][b] = false;
        edges[b][a] = false;
    }


    UnionFind uf(n);

    rep(i, n) {
        rep(j, n) {
            if (edges[i][j])uf.connect(i, j);
        }
    }


    rep(i, n) {
        if (uf.root(i) != i) continue;
        bool b = is_2(i, edges);
        if (!b) {
            cout << -1 << endl;
            ret();
        }
    }

    vector<bool> dp(n + 1, false);
    dp[0] = true;

    rep(i, n) {
        if (uf.root(i) != i) continue;
        P p = count_2(i, edges);

        vector<bool> next(n + 1, false);

        auto set = [&](int i) {
            if (i > n) return;
            next[i] = true;
        };

        rep(j, n + 1) {
            if (!dp[j]) continue;
            set(j + p.first);
            set(j + p.second);
        }

        dp = next;
    }


    ll ans = INF;
    rep(i, n + 1) {
        if (!dp[i]) continue;
        ll a = i;
        ll b = n - a;

        ll x = a * (a - 1) / 2;
        ll y = b * (b - 1) / 2;

        ll now = x + y;

        cmin(ans, now);

    }

    cout << ans << endl;

}