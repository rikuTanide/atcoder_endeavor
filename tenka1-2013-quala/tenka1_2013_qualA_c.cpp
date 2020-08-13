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

int rec(int h, int w, int y, int x, vector<vector<int>> &board) {
    if (y == h) return 1;

    int ans = 0;
    for (int k = 1; k <= 3; k++) {

        bool hb = [&] {
            // 縦チェック
            for (int ny = max(y - k, 0); ny < y; ny++) {
                if (board[ny][x] == k) return false;
            }
            return true;
        }();

        bool vb = [&] {
            // 横チェック
            for (int nx = max(x - k, 0); nx < x; nx++) {
                if (board[y][nx] == k) return false;
            }
            return true;
        }();

        if (!(vb && hb)) continue;
        board[y][x] = k;
        ans += rec(h, w, y + ((x + 1) / w), (x + 1) % w, board);
        board[y][x] = -1;
    }
    return ans;
}

int main2() {

    map<int, vector<P>> ans;

    for (int h = 1; h <= 30; h++) {
        for (int w = 1; w <= 20; w++) {
            vector<vector<int>> board(h, vector<int>(w, -1));
            int now = rec(h, w, 0, 0, board);
            ans[now].push_back({h, w});
        }
    }

    for (auto &e : ans) {
        cout << e.first << endl;
        for (P p : e.second) printf(" %lld %lld\n", p.first, p.second);
    }

}


int main() {
    int n, m;
    cin >> n >> m;
    if (n > m) swap(n, m);

    int ans = [&] {
        if (n <= 5 && m <= 5) {
            int h = n;
            int w = m;
            vector<vector<int>> board(h, vector<int>(w, -1));
            int now = rec(h, w, 0, 0, board);
            return now;
        }

        if (n == 1) {
            m %= 4;
            if (m == 0) {
                return 10;
            } else if (m == 1) {
                return 9;
            } else if (m == 2) {
                return 8;
            } else if (m == 3) {
                return 9;
            }
        }

        int t = (n + m) % 4;
        if (t == 0) {
            return 18;
        } else if (t == 1) {
            return 20;
        } else if (t == 2) {
            return 18;
        } else if (t == 3) {
            return 16;
        }

    }();
    cout << ans << endl;
}