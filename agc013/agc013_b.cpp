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

vector<int> dfs(int now, set<int> &used, vector<vector<int>> &g) {

    for (int next : g[now]) {
        if (contain(used, next))continue;
        used.insert(next);
        auto ans = dfs(next, used, g);
        ans.push_back(now);
        return ans;
    }

    return {now};

}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;

        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);

    }

    int s1 = 0, s2 = g[0][0];

    set<int> used;
    used.insert(s1);
    used.insert(s2);
    vector<int> v1 = dfs(s1, used, g);
    vector<int> v2 = dfs(s2, used, g);

    cout << (v1.size() + v2.size()) << endl;

    reverse(v2.begin(), v2.end());
    for (int i : v1) cout << i + 1 << ' ';
    for (int i : v2) cout << i + 1 << ' ';
    cout << endl;


}

