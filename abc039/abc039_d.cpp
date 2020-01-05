#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

//#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX;
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

int checkColor(int y, int x, vector<vector<char>> &picture) {
    rep(i, 3) {
        rep(j, 3) {
            int my = y - 1 + i;
            int mx = x - 1 + j;

            if (my == -1) continue;
            if (my == picture.size()) continue;
            if (mx == -1) continue;
            if (mx == picture[my].size()) continue;

            if (picture[my][mx] == '.') return '.';

        }
    }
    return '#';
}

int compress(int y, int x, vector<vector<char>> &restoration) {
    rep(i, 3) {
        rep(j, 3) {
            int my = y - 1 + i;
            int mx = x - 1 + j;

            if (my == -1) continue;
            if (my == restoration.size()) continue;
            if (mx == -1) continue;
            if (mx == restoration[my].size()) continue;

            if (restoration[my][mx] == '#') return '#';

        }
    }
    return '.';
}


int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<char>> picture(h, vector<char>(w, ' '));
    vector<vector<char>> restoration(h, vector<char>(w, ' '));
    vector<vector<char>> new_picture(h, vector<char>(w, ' '));

    rep(i, h) rep(j, w) cin >> picture[i][j];

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            restoration[y][x] = checkColor(y, x, picture);
        }
    }


    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            new_picture[y][x] = compress(y, x, restoration);
        }
    }

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (picture[y][x] != new_picture[y][x]) {
                cout << "impossible" << endl;
                return 0;
            }
        }
    }

    cout << "possible" << endl;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            cout << restoration[y][x];
        }
        cout << endl;
    }
}