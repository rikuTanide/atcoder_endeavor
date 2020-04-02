#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep(i, n) for (ll i = 0; i < (n); ++i)
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

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//const ll mod = 1e10;
typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

#include <iostream>
#include <vector>

using namespace std;


int main() {
    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> edges(n);
    rep(i, m) {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        edges[u].push_back(v);
    }

    vector<vector<ll>> dp(n, vector<ll>(3, INF));

    struct Task {
        ll next, cost;
    };

    queue<Task> q;

    ll s, t;
    cin >> s >> t;
    s--;
    t--;
    q.push({s, 0});

    while (!q.empty()) {
        Task front = q.front();
        q.pop();
        for (ll to : edges[front.next]) {
            ll next_cost = front.cost + 1;
            ll next_cost_type = next_cost % 3;
            if (dp[to][next_cost_type] <= next_cost) {
                continue;
            }
            q.push({to, next_cost});
            dp[to][next_cost_type] = next_cost;
        }
    }

    if (dp[t][0] == INF) {
        cout << -1 << endl;
    } else {
        cout << dp[t][0] / 3 << endl;
    }

}
