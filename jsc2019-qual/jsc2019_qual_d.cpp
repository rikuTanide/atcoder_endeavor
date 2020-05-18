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


void dfs(int l, int r, int level, vector<vector<ll>> &ans) {
    if (l + 1 == r) return;
    int mid = (l + r) / 2;

    for (int x = l; x < mid; x++) {
        for (int y = mid; y < r; y++) {
            ans[x][y] = level;
            ans[y][x] = level;
        }
    }

    dfs(l, mid, level + 1, ans);
    dfs(mid, r, level + 1, ans);

}

int main() {
    int n;
    cin >> n;

    vector<vector<ll>> ans(n, vector<ll>(n));
    dfs(0, n, 1, ans);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (j != i + 1) cout << ' ';
            cout << ans[i][j];
        }
        cout << endl;
    }
}
