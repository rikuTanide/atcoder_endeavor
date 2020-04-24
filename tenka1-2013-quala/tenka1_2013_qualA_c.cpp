#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

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

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

void print(vector<vector<int>> &board) {
    rep(y, board.size()) {
        rep(x, board[y].size()) {
            cout << board[y][x] << ' ';
        }
        cout << endl;
    }
}

int rec(vector<vector<int>> &board, int y, int x, int m, int n) {

    auto ok = [&](int y, int x, int i) {
        if (y < 0 || x < 0) return true;
        return board[y][x] != i;
    };

    int now = 0;
    for (int i = 1; i <= 3; i++) {
        // 1;
        board[y][x] = i;
        bool b = [&] {
            for (int j = 1; j <= i; j++) {
                if (!ok(y - j, x, i))return false;
                if (!ok(y, x - j, i))return false;
            }
            return true;
        }();
        if (!b) continue;
        if (m - 1 == y && n - 1 == x) {
//            print(board);
            now++;
        } else {
            int ny = y;
            int nx = x + 1;
            if (nx == n) {
                nx = 0;
                ny++;
            }
            now += rec(board, ny, nx, m, n);
        }
    }
    return now;
}

void small(int m, int n) {
    vector<vector<int>> board(m, vector<int>(n, -1));
    cout << rec(board, 0, 0, m, n) << endl;
}

int main() {
    int m, n;
    cin >> m >> n;

    if (m > n) swap(m, n);
    assert(m <= n);
    if (n <= 100) {
        small(m, n);
        ret();
    }
    int mn = (m + n) % 4;
    if (mn == 0) cout << 18 << endl;
    else if (mn == 1) cout << 20 << endl;
    else if (mn == 2) cout << 18 << endl;
    else if (mn == 3) cout << 16 << endl;
}

