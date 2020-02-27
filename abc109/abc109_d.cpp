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

struct Move {
    int x1, y1, x2, y2;
};

struct Grid {
    int x, y, a;
};

int main() {
    int h, w;
    cin >> h >> w;

    vector<Grid> grid(h * w);
    for (int i = 0; i < h * w; i++) {
        int a;
        cin >> a;
        grid[i].x = i % w;
        grid[i].y = i / w;
        grid[i].a = a;
    }

    for (int y = 0; y < h; y++) {
        if (y % 2 == 0) continue;
        reverse(grid.begin() + (w * y), grid.begin() + (w * (y + 1)));
    }


    vector<Move> move;
    for (int i = 0; i < h * w - 1; i++) {
        if (grid[i].a % 2 == 0) continue;
        grid[i].a--;
        grid[i + 1].a++;

        Move m;
        m.x1 = grid[i].x;
        m.y1 = grid[i].y;
        m.x2 = grid[i + 1].x;
        m.y2 = grid[i + 1].y;
        move.push_back(m);
    }

    cout << move.size() << endl;

    for (Move m: move) {
        printf("%d %d %d %d\n", m.y1 + 1, m.x1 + 1, m.y2 + 1, m.x2 + 1);
    }

}