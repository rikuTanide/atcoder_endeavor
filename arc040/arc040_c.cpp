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
    int n;
    cin >> n;

    vector<vector<char>> board(n, vector<char>(n));
    rep(i, n) rep(j, n)cin >> board[i][j];

    vector<bool> has(n);
    rep(i, n) {
        for (char c : board[i]) if (c == '.') has[i] = true;
    }

    vector<vector<int>> lefts(n, vector<int>(n, -1));
    vector<vector<int>> rights(n, vector<int>(n, -1));

    rep(y, n) {
        if (!has[y]) continue;
        rep(x, n) {
            if (board[y][x] == '.') {
                lefts[y][x] = x;
            } else {
                if (x == 0) lefts[y][x] = -1;
                else lefts[y][x] = lefts[y][x - 1];
            }
        }
    }

    rep(y, n) {
        if (!has[y]) continue;
        for (int x = n - 1; x >= 0; x--) {
            if (board[y][x] == '.') rights[y][x] = x;
            else {
                if (x == n - 1) rights[y][x] = -1;
                else rights[y][x] = rights[y][x + 1];
            }
        }
    }


    vector<P> range(n);
    rep(i, n) range[i].first = rights[i].front();
    rep(i, n) range[i].second = lefts[i].back();


    auto paint = [&](int i, int left, int right) {
        if (left <= range[i].first && range[i].second <= right) {
            has[i] = false;
            return;
        } else {
            P l(0, left - 1);
            P r(right + 1, n - 1);
            int nl = -1;
            int nr = -1;

            if (l.first <= l.second) {
                nl = rights[i][l.first];
                nr = lefts[i][l.second];
            }
            if (r.first <= r.second) {
                if (nl == -1) {
                    nl = rights[i][r.first];
                }
                nr = lefts[i][r.second];
            }

            assert(nl >= 0);
            assert(nr >= 0);

            range[i].first = nl;
            range[i].second = nr;
        }
    };

    int ans = 0;
    rep(i, n) {
        if (!has[i]) continue;
        ans++;
        paint(i, range[i].first, range[i].second);
        if (i + 1 < n) {
            paint(i + 1, range[i].second, n - 1);
        }
    }
    cout << ans << endl;
}
