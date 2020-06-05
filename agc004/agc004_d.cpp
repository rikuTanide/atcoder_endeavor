#include <bits/stdc++.h>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<double, ll> P;
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
typedef priority_queue<string, vector<string>, greater<string> > PQ_ASK;

int dfs(int i, int k, vector<int> &parents, vector<vector<int>> &edges, vector<bool> &change) {
    int child_depth = 0;
    for (int to : edges[i]) {
        int now = dfs(to, k, parents, edges, change);
        cmax(child_depth, now);
    }
    int depth = child_depth + 1;
    if (depth == k && parents[i] != 0) {
        parents[i] = 0;
        change[i] = true;
        return 0;
    }
    return depth;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> edges(n);
    vector<bool> change(n, false);

    vector<int> parents(n);
    rep(i, n) {
        int a;
        cin >> a;
        a--;

        if (i == 0) {
            if (a != 0) {
                change[0] = true;
            }
            continue;
        }

        edges[a].push_back(i);
        parents[i] = a;
    }

    vector<int> ds(n);

    dfs(0, k, parents, edges, change);

    int ans = count(change.begin(), change.end(), true);
    cout << ans << endl;

}
