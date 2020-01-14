#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

//#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef pair<int, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;

int toID(int i, int j) {
    return i * 3 + j;
}

int naoko_score(int k, vector<vector<int>> &bs, vector<vector<int>> &cs) {
    int score = 0;
    rep(i, 2)
        rep(j, 3) {
            int p = toID(i, j);
            int q = toID(i + 1, j);

            bool pb = (k >> p) & 1;
            bool qb = (k >> q) & 1;

            if (pb != qb) score += bs[i][j];
        }
    rep(i, 3)
        rep(j, 2) {
            int p = toID(i, j);
            int q = toID(i, j + 1);

            bool pb = (k >> p) & 1;
            bool qb = (k >> q) & 1;

            if (pb != qb) score += cs[i][j];
        }
    return score;
}

int chokudai_score(int k, vector<vector<int>> &bs, vector<vector<int>> &cs) {
    int score = 0;
    rep(i, 2)
        rep(j, 3) {
            int p = toID(i, j);
            int q = toID(i + 1, j);

            bool pb = (k >> p) & 1;
            bool qb = (k >> q) & 1;

            if (pb == qb) score += bs[i][j];
        }
    rep(i, 3)
        rep(j, 2) {
            int p = toID(i, j);
            int q = toID(i, j + 1);

            bool pb = (k >> p) & 1;
            bool qb = (k >> q) & 1;

            if (pb == qb) score += cs[i][j];
        }
    return score;
}

void foreach_permutation(int n, std::function<const void(vector<int> &)> f) {
    vector<int> indexes(n);
    for (int i = 0; i < n; i++) indexes[i] = i;
    do {
        f(indexes);
    } while (std::next_permutation(indexes.begin(), indexes.end()));
}

int create_board(vector<int> &indexes) {
    int k = 0;
    for (int i = 0; i < 9; i++) {
        if (i % 2 == 1) {
            k += (1 << i);
        }
    }
    return k;
}

int check(int turn, vector<vector<int>> &bs, vector<vector<int>> &cs) {
    map<vector<int>, int> m;
    foreach_permutation(9, [&](vector<int> &indexes) {
        if (turn % 2 == 1) {
            int board = create_board(indexes);
            int score = naoko_score(board, bs, cs);
            vector<int> before_index(turn - 1);
            copy(indexes.begin(), indexes.begin() + turn - 1, before_index.begin());
            m[before_index] = score;
        }
    });
    return 0;
}

int main() {
    vector<vector<int>> bs(2, vector<int>(3));
    vector<vector<int>> cs(3, vector<int>(2));

    rep(i, 2)rep(j, 3) cin >> bs[i][j];
    rep(i, 3)rep(j, 2) cin >> cs[i][j];

    cout << chokudai_score(0b010100101, bs, cs) << endl;
    cout << naoko_score(0b010100101, bs, cs) << endl;

    map<vector<int>, int> m;
    check(9, bs, cs);

}