#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
//using namespace boost::multiprecision;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
const ll INF = 1e15;
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
const int mod = 1000000007;
//const ll mod = 1e10;
typedef priority_queue<long long, vector<long long>, greater<long long> > PQ_ASK;

struct G {
    int x;
    int y;
    int depth;
};

int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<char>> grid(h, vector<char>(w, ' '));
    rep(y, h) rep(x, w) cin >> grid[y][x];
    int white_count = 0;
    rep(y, h) rep(x, w) if (grid[y][x] == '.') white_count++;

    queue<G> q;
    q.push({0, 0, 1});

    auto can = [&](int x, int y) {
        if (x == -1 || x == w) return false;
        if (y == -1 || y == h) return false;
        if (grid[y][x] == '#') return false;
        return true;
    };

    while (!q.empty()) {
        G g = q.front();
        q.pop();
        if (g.x == w - 1 && g.y == h - 1) {
            cout << white_count - g.depth << endl;
            ret();
        }
        grid[g.y][g.x] = '#';

        if (can(g.x + 1, g.y)) q.push({g.x + 1, g.y, g.depth + 1});
        if (can(g.x - 1, g.y)) q.push({g.x - 1, g.y, g.depth + 1});
        if (can(g.x, g.y + 1)) q.push({g.x, g.y + 1, g.depth + 1});
        if (can(g.x, g.y - 1)) q.push({g.x, g.y - 1, g.depth + 1});
    }

    cout << -1 << endl;

}
