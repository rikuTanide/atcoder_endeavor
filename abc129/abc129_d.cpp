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

int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<char>> board(h, vector<char>(w));
    rep(y, h) rep(x, w) cin >> board[y][x];

    vector<vector<int>> horizontal(h, vector<int>(w, 0));
    vector<vector<int>> vertical(h, vector<int>(w, 0));

    for (int y = 0; y < h; y++) {
        horizontal[y][0] = board[y][0] == '.' ? 1 : 0;
        for (int x = 1; x < w; x++) {
            if (board[y][x] == '.') {
                horizontal[y][x] = horizontal[y][x - 1] + 1;
            } else {
                horizontal[y][x] = 0;
            }
        }
    }

    for (int y = 0; y < h; y++) {
        for (int x = w - 2; x >= 0; x--) {
            if (horizontal[y][x] == 0) continue;
            horizontal[y][x] = max(horizontal[y][x + 1], horizontal[y][x]);
        }
    }

    for (int x = 0; x < w; x++) {
        vertical[0][x] = board[0][x] == '.' ? 1 : 0;
        for (int y = 1; y < h; y++) {
            if (board[y][x] == '.') {
                vertical[y][x] = vertical[y - 1][x] + 1;
            } else {
                vertical[y][x] = 0;
            }
        }
    }


    for (int x = 0; x < w; x++) {
        for (int y = h - 2; y >= 0; y--) {
            if (vertical[y][x] == 0) continue;
            vertical[y][x] = max(vertical[y + 1][x], vertical[y][x]);
        }
    }

    int ans = 0;
    rep(y, h) rep(x, w) {
            if (board[y][x] == '#') continue;
            int now = horizontal[y][x] + vertical[y][x] - 1;
            cmax(ans, now);
        }

    cout << ans << endl;
}