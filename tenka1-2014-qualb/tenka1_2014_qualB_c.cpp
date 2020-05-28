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

std::istream &operator>>(std::istream &in, set<char> &o) {
    string a;
    in >> a;
    for (char c : a) o.insert(c);
    return in;
}

std::istream &operator>>(std::istream &in, queue<int> &o) {
    ll a;
    in >> a;
    o.push(a);
    return in;
}

bool contain(set<char> &s, char a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);


typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;


int to_id(int n, int y, int x) {
    return y * n + x;
};

struct Direction {
    int y, x;
};

vector<Direction> directions = {
        {0,  1},
        {1,  0},
        {0,  -1},
        {-1, 0},
};


bool reachable(int n, int y, int x) {
    if (x == -1 || x == n || y == -1 || y == n) return false;
    return true;
};


vector<vector<char>> simulate(int n, vector<vector<char>> &v) {
    vector<vector<char>> ans(n, vector<char>(n));
    rep(y, n) rep(x, n) {
            int b = 0;
            for (Direction d : directions) {
                int nx = x + d.x;
                int ny = y + d.y;
                if (!reachable(n, ny, nx)) {
                    continue;
                }
                if (v[ny][nx] == '#') b++;
            }

            ans[y][x] = b % 2 == 0 ? '.' : '#';
        }
    return ans;
}

int main() {
    int n;
    cin >> n;

    assert(n <= 3);
    
    vector<vector<char>> board(n, vector<char>(n));
    rep(y, n) rep(x, n) cin >> board[y][x];


    rep(i, 1 << (n * n)) {
        vector<vector<char>> v(n, vector<char>(n));
        rep(y, n) rep(x, n) {
                int id = to_id(n, y, x);
                bool b = (i >> id) & 1;
                v[y][x] = b ? '#' : '.';
            }
        auto u = simulate(n, v);
        if (u == board) {
            rep(y, n) {
                rep(x, n) cout << v[y][x];
                cout << endl;
            }
            ret();
        }
    }


}

