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

int rev(int x) {
    int ans = 0;
    while (x > 0) {
        ans *= 10;
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

P next(int x, int y) {
    if (x < y) {
        x = rev(x);
    } else {
        y = rev(y);
    }
    if (x < y) {
        y = y - x;
    } else {
        x = x - y;
    }
    return P(x, y);
}

int main() {
    int MAX = 1000;
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(MAX * MAX);
    vector<int> deg(MAX * MAX);


    for (int x = 1; x < MAX; x++) {
        for (int y = 1; y < MAX; y++) {
            P nt = next(x, y);

            int from = x * MAX + y;
            int to = nt.first * MAX + nt.second;

            g[to].push_back(from);
            deg[from]++;

        }
    }

    queue<int> q;
    vector<int> visited(MAX * MAX, 0);

    rep(i, MAX * MAX) if (deg[i] == 0) q.push(i);

    while (!q.empty()) {
        int from = q.front();
        q.pop();
        visited[from] = true;

        for (int to : g[from]) {
            if (visited[to]) continue;
            deg[to]--;
            if (deg[to] == 0) q.push(to);
        }
    }

    int ans = 0;
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            int id = x * MAX + y;
            if (!visited[id]) ans++;
        }
    }
    cout << ans << endl;
}
