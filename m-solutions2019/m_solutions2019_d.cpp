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
    int n;
    cin >> n;

    vector<vector<ll>> edges(n);
    rep(i, n - 1) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    vector<ll> cs(n);
    rep(i, n) cin >> cs[i];

    priority_queue<ll> q;
    for (ll l : cs) q.push(l);

    vector<ll> ans(n, -1);
    queue<ll> r;

    int f1 = 0, f2 = edges[0][0];
    ans[f1] = q.top();
    q.pop();
    r.push(f1);
    ans[f2] = q.top();
    q.pop();
    r.push(f2);

    while (!r.empty()) {
        ll t = r.front();
        r.pop();
        for (ll next : edges[t]) {
            if (ans[next] != -1) continue;
            assert(!q.empty());
            ans[next] = q.top();
            q.pop();
            r.push(next);
        }
    }

    sort(cs.begin(), cs.end());
    ll sum = accumulate(cs.begin(), cs.end() - 1, 0ll);
    cout << sum << endl;

    for (ll l : ans) cout << l << ' ';
    cout << endl;

}
