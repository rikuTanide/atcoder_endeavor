#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<int, int> P;
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

int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<char>> picture(h, vector<char>(w));
    rep(y, h) rep(x, w)cin >> picture[y][x];

    struct Direction {
        int x, y;
    };

    vector<Direction> directions = {
            {0,  1},
            {1,  1},
            {1,  0},
            {1,  -1},
            {0,  -1},
            {-1, -1},
            {-1, 0},
            {-1, 1},
            {0,  0},
    };

    vector<vector<char>> expand(h, vector<char>(w, '#'));

    auto white = [&](int x, int y) {
        if (x == -1 || x == w || y == -1 || y == h) return;
        expand[y][x] = '.';
    };

    rep(y, h) rep(x, w) {
            if (picture[y][x] == '#') continue;

            for (Direction d : directions) {
                ll nx = x + d.x;
                ll ny = y + d.y;

                white(nx, ny);
            }
        }

    vector<vector<char>> compress(h, vector<char>(w, '.'));
    auto black = [&](int x, int y) {
        if (x == -1 || x == w || y == -1 || y == h) return;
        compress[y][x] = '#';
    };

    rep(y, h) rep(x, w) {
            if (expand[y][x] == '.') continue;

            for (Direction d : directions) {
                ll nx = x + d.x;
                ll ny = y + d.y;

                black(nx, ny);
            }
        }

    cout << (picture == compress ? "possible" : "impossible") << endl;
    if (picture == compress) {
        rep(y, h) {
            rep(x, w) cout << expand[y][x];
            cout << endl;
        }
    }

}
