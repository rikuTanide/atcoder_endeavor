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


int main() {

    int n;
    cin >> n;

    vector<vector<int>> edges(n);

    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        edges[a].push_back(b);
        edges[b].push_back(a);

    }

    PQ_ASK q;
    q.push(0);
    vector<bool> used(n, false);
    vector<int> ans;
    while (!q.empty()) {
        int t = q.top();
        q.pop();
        ans.push_back(t + 1);
        used[t] = true;
        for (int j : edges[t]) {
            if (used[j]) continue;
            q.push(j);
        }
    }

    rep(i, n - 1) cout << ans[i] << ' ';
    cout << ans.back() << endl;

}

