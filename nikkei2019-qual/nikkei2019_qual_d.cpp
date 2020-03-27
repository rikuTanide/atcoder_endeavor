#include <bits/stdc++.h>
#include <cmath>

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
typedef priority_queue<string, vector<string>, greater<string> > PQ_ASK;

#include <iostream>
#include <vector>

using namespace std;

const int mod = 1000000007;


int main() {
    int n, m;
    cin >> n >> m;
    int o = n + m;
    int p = o - 1;
    vector<P> edges(p);
    rep(i, p) cin >> edges[i].first >> edges[i].second;
    rep(i, p) edges[i].first--;
    rep(i, p) edges[i].second--;

    int root = -1;
    vector<int> parent_count(n, 0);
    rep(i, p) parent_count[edges[i].second]++;
    rep(i, n) if (parent_count[i] == 0) root = i;


    vector<vector<int>> tos(n);

    for (P q : edges) {
        tos[q.first].push_back(q.second);
    }

    vector<int> parents(n, -1);

    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int from = q.front();
        q.pop();
        for (int to : tos[from]) {
            parent_count[to]--;
            if (parent_count[to] == 0) {
                parents[to] = from;
                q.push(to);
            }
        }
    }

    for (int parent : parents) cout << parent + 1 << endl;
}
