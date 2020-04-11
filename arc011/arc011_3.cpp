#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
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

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//const ll mod = 1e10;
typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

bool is_diff1(string &s, string &t) {
    int count = 0;
    rep(i, s.size()) {
        if (s[i] != t[i]) count++;
    }
    return count == 1;
}

vector<string> bfs(vector<string> &vs, vector<vector<int>> &edges, int n, int start, int goal) {
    vector<ll> dist(n, INF), pre(n, -1);
    queue<ll> q;
    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : edges[v]) {
            if (dist[u] != INF) continue;
            pre[u] = v;
            dist[u] = dist[v] + 1;
            q.push(u);
        }
    }
    if (dist[goal] == INF) return vector<string>{};
    int i = goal;
    vector<string> ans;
    while (i != start) {
        ans.push_back(vs[i]);
        i = pre[i];
    }
    ans.push_back(vs[start]);
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    string start, end;
    cin >> start >> end;

    if (start == end) {
        cout << 0 << endl << start << endl << end << endl;
        ret();
    }

    int n;
    cin >> n;
    vector<string> vs(n);
    rep(i, n) cin >> vs[i];

    vector<string> vs2 = {start};
    for (string &s : vs) vs2.push_back(s);
    vs2.push_back(end);

    vector<vector<int>> edges(n + 2);
    rep(i, n + 2) {
        rep(j, n + 2) {
            if (!is_diff1(vs2[i], vs2[j])) continue;
            edges[i].push_back(j);
        }
    }

    vector<string> ans = bfs(vs2, edges, n + 2, 0, n + 1);
    if (ans.empty()) {
        cout << -1 << endl;
        ret();
    }
    cout << ans.size() - 2 << endl;
    for (string &s : ans) cout << s << endl;
}
