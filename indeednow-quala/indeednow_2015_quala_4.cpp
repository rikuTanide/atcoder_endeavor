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

std::istream &operator>>(std::istream &in, set<string> &o) {
    string a;
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

bool up(vector<int> &board, int h, int w) {
    auto it = find(board.begin(), board.end(), 0);
    int id = distance(board.begin(), it);
    if (id < w) return false;
    swap(board[id], board[id - w]);
    return true;
}

bool down(vector<int> &board, int h, int w) {
    auto it = find(board.begin(), board.end(), 0);
    int id = distance(board.begin(), it);
    if (id + w >= h * w) {
        return false;
    }
    swap(board[id], board[id + w]);
    return true;
}

bool right(vector<int> &board, int h, int w) {
    auto it = find(board.begin(), board.end(), 0);
    int id = distance(board.begin(), it);
    if ((id + 1) % w == 0) return false;
    swap(board[id], board[id + 1]);
    return true;
}

bool left(vector<int> &board, int h, int w) {
    auto it = find(board.begin(), board.end(), 0);
    int id = distance(board.begin(), it);
    if (id % w == 0) return false;
    swap(board[id], board[id - 1]);
    return true;
}

vector<int> clear;

bool is_enable(int depth, vector<int> &board, int ma, int h, int w) {

    int ans = 0;
    rep(i, h * w) {
        if (i == 0) continue;
        auto b_it = find(board.begin(), board.end(), i);
        int b_id = distance(board.begin(), b_it);

        int b_x = b_id % w;
        int b_y = b_id / w;

        auto c_it = find(clear.begin(), clear.end(), i);
        int c_id = distance(clear.begin(), c_it);

        int c_x = c_id % w;
        int c_y = c_id / w;
        int now = abs(b_x - c_x) + abs(b_y - c_y);
        ans += now;
    }

    if (ans + depth <= ma) {
        return true;
    } else {
        return false;
    }

}


int dfs(vector<int> &board, char c, int depth, int ma, int h, int w) {

    if (board == clear) {
        return depth;
    }


    int ans = INT_MAX;
    if (c != 'd' && up(board, h, w)) {
        if (is_enable(depth + 1, board, ma, h, w)) {
            int now = dfs(board, 'u', depth + 1, ma, h, w);
            cmin(ans, now);

        }
        down(board, h, w);
    }
    if (c != 'u' && down(board, h, w)) {
        if (is_enable(depth + 1, board, ma, h, w)) {
            int now = dfs(board, 'd', depth + 1, ma, h, w);
            cmin(ans, now);

        }
        up(board, h, w);
    }
    if (c != 'r' && left(board, h, w)) {
        if (is_enable(depth + 1, board, ma, h, w)) {
            int now = dfs(board, 'l', depth + 1, ma, h, w);
            cmin(ans, now);

        }
        right(board, h, w);
    }
    if (c != 'l' && right(board, h, w)) {
        if (is_enable(depth + 1, board, ma, h, w)) {
            int now = dfs(board, 'r', depth + 1, ma, h, w);
            cmin(ans, now);

        }
        left(board, h, w);
    }
    return ans;

}

int main() {

    int h, w;
    cin >> h >> w;

    clear.resize(h * w, 0);
    rep(i, h * w) clear[i] = i + 1;
    clear.back() = 0;


    vector<int> board(h * w, 0);
    rep(i, h * w) cin >> board[i];
    for (int i = 1; i <= 24; i++) {
        int ans = dfs(board, ' ', 0, i, h, w);
        if (ans != INT_MAX) {
            cout << ans << endl;
            return 0;
        }
    }

}