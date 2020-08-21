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


string to_upper(string str) {
    int diff = 'a' - 'A';
    for (int i = 0; i < str.size(); i++) {
        char c = str[i];
        if ('A' <= c && c <= 'Z') {
            c += diff;
            str[i] = c;
        }
    }
    return str;
}

vector<int> up(vector<int> &board, int h, int w) {
    auto it = find(board.begin(), board.end(), 0);
    int id = distance(board.begin(), it);
//    if (id == 0 || id == 1 || id == 2) {
    if (id < w) {
        return vector<int>(0);
    }
    vector<int> res = board;
    swap(res[id], res[id - w]);
    return res;
}

vector<int> down(vector<int> &board, int h, int w) {
    auto it = find(board.begin(), board.end(), 0);
    int id = distance(board.begin(), it);
//    if (id == 6 || id == 7 || id == 8) {
    if (id + w >= h * w) {
        return vector<int>(0);
    }
    vector<int> res = board;
    swap(res[id], res[id + w]);
    return res;
}

vector<int> right(vector<int> &board, int h, int w) {
    auto it = find(board.begin(), board.end(), 0);
    int id = distance(board.begin(), it);
//    if (id == 2 || id == 5 || id == 8) {
    if (id % w == w - 1) {
        return vector<int>(0);
    }
    vector<int> res = board;
    swap(res[id], res[id + 1]);
    return res;
}

vector<int> left(vector<int> &board, int h, int w) {
    auto it = find(board.begin(), board.end(), 0);
    int id = distance(board.begin(), it);
//    if (id == 0 || id == 3 || id == 6) {
    if (id % w == 0) {
        return vector<int>(0);
    }
    vector<int> res = board;
    swap(res[id], res[id - 1]);
    return res;
}

struct Board {
    vector<int> board;
    int depth;
};

int bfs(vector<int> &board, int h, int w) {

    vector<int> clear;
    for (int i = 1; i < h * w; i++)clear.push_back(i);
    clear.push_back(0);

    set<vector<int> > used;

    queue<Board> q;
    q.push({board, 0});

    while (!q.empty()) {
        Board top = q.front();
        q.pop();
        if (top.board == clear) {
            return top.depth;
        }
        if (used.find(top.board) != used.end()) {
            continue;
        }
        used.insert(top.board);

        vector<int> u = up(top.board, h, w),
                d = down(top.board, h, w),
                r = right(top.board, h, w),
                l = left(top.board, h, w);

        if (!u.empty()) {
            q.push({u, top.depth + 1});
        }
        if (!d.empty()) {
            q.push({d, top.depth + 1});
        }
        if (!r.empty()) {
            q.push({r, top.depth + 1});
        }
        if (!l.empty()) {
            q.push({l, top.depth + 1});
        }
    }

    return -1;
}

int main() {

    int h, w;
    cin >> h >> w;

    vector<int> board(h * w, 0);
    rep(i, h * w) cin >> board[i];

    int ans = bfs(board, h, w);

    cout << ans << endl;

}