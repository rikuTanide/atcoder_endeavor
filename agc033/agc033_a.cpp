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
typedef priority_queue<string, vector<string>, greater<string> > PQ_ASK;

struct Reach {
    int x, y, time;
};

int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<char>> grid(h, vector<char>(w));
    rep(y, h) rep(x, w) cin >> grid[y][x];

    vector<vector<int>> distances(h, vector<int>(w, INT_MAX));
    rep(y, h) rep(x, w) if (grid[y][x] == '#') distances[y][x] = 0;

    queue<Reach> q;
    rep(y, h) rep(x, w) if (grid[y][x] == '#') q.push({x, y, 0});

    auto set = [&](int x, int y, int time) {
        if (x == -1)return;;
        if (x == w)return;;
        if (y == -1)return;;
        if (y == h)return;;
        if (distances[y][x] <= time) return;
        distances[y][x] = time;
        q.push({x, y, time});
    };

    while (!q.empty()) {
        auto f = q.front();
        q.pop();
        set(f.x - 1, f.y, f.time + 1);
        set(f.x + 1, f.y, f.time + 1);
        set(f.x, f.y - 1, f.time + 1);
        set(f.x, f.y + 1, f.time + 1);
    }
    int ans = 0;
    rep(y, h) rep(x, w) cmax(ans, distances[y][x]);
    cout << ans << endl;

}