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
            k += (1 << indexes[i]);
        }
    }
    return k;
}

struct Score {
    int naoko;
    int chokudai;
};

void check_last_turn(vector<vector<int>> &bs, vector<vector<int>> &cs, map<vector<int>, Score> &m) {
    foreach_permutation(9, [&](vector<int> &indexes) {
        int board = create_board(indexes);
        int n_score = naoko_score(board, bs, cs);
        int c_score = chokudai_score(board, bs, cs);
        vector<int> before_index(8);
        copy(indexes.begin(), indexes.begin() + 8, before_index.begin());
        if (m.find(indexes) == m.end()) {
            m[before_index] = Score{n_score, c_score};
        } else {
            if (m[before_index].chokudai < c_score) {
                m[before_index].chokudai = c_score;
                m[before_index].naoko = n_score;
            }
        }
    });
}

void check_naoko(map<vector<int>, Score> &m, map<vector<int>, Score> &nm, int turn) {
    for (auto e : m) {
        vector<int> indexes = e.first;
        Score score = e.second;
        vector<int> before_index(turn - 1);
        copy(indexes.begin(), indexes.begin() + turn - 1, before_index.begin());
        if (nm.find(indexes) == nm.end()) {
            nm[before_index] = Score{score.naoko, score.chokudai};
        } else {
            if (nm[before_index].naoko < score.naoko) {
                nm[before_index] = score;
            }
        }
    }
}


void check_chokudai(map<vector<int>, Score> &m, map<vector<int>, Score> &nm, int turn) {
    for (auto e : m) {
        vector<int> indexes = e.first;
        Score score = e.second;
        vector<int> before_index(turn - 1);
        copy(indexes.begin(), indexes.begin() + turn - 1, before_index.begin());
        if (nm.find(indexes) == nm.end()) {
            nm[before_index] = Score{score.naoko, score.chokudai};
        } else {
            if (nm[before_index].chokudai < score.chokudai) {
                nm[before_index] = score;
            }
        }
    }
}


int main() {
    vector<vector<int>> bs(2, vector<int>(3));
    vector<vector<int>> cs(3, vector<int>(2));

    rep(i, 2)rep(j, 3) cin >> bs[i][j];
    rep(i, 3)rep(j, 2) cin >> cs[i][j];

    cout << chokudai_score(0b010100101, bs, cs) << endl;
    cout << naoko_score(0b010100101, bs, cs) << endl;

    map<vector<int>, Score> m9;
    map<vector<int>, Score> m8;
    map<vector<int>, Score> m7;
    map<vector<int>, Score> m6;
    map<vector<int>, Score> m5;
    map<vector<int>, Score> m4;
    map<vector<int>, Score> m3;
    map<vector<int>, Score> m2;
    map<vector<int>, Score> m1;
    check_last_turn(bs, cs, m9);

    check_naoko(m9, m8, 8);
    check_chokudai(m8, m7, 7);
    check_naoko(m7, m6, 6);
    check_chokudai(m6, m5, 5);
    check_naoko(m5, m4, 4);
    check_chokudai(m4, m3, 3);
    check_naoko(m3, m2, 2);
    check_chokudai(m2, m1, 1);


    cout << endl;
}