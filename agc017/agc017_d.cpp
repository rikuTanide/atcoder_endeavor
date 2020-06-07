#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
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

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;


int dfs(vector<vector<int>> &edges, int now, int prev) {
    int grd = 0;
    for (int next : edges[now]) {
        if (next == prev) continue;
        grd ^= dfs(edges, next, now);
    }
    grd++;
    return grd;
}

int main() {
    int n;
    cin >> n;


    vector<vector<int>> edges(n);
    rep(i, n - 1) {
        int x, y;
        cin >> x >> y;

        x--;
        y--;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    int res = dfs(edges, 0, -1);
    res--;
    cout << (res == 0 ? "Bob" : "Alice") << endl;

}
