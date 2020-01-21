#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX / 100;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;

bool check(vector<int> choose, int n, int k, vector<vector<int>> &points) {
    int point = 0;
    rep(i, n) {
        int c = choose[i];
        int t = points[i][c];
        point = point ^ t;
    }
    return point == 0;
}

bool recursive(int depth, vector<int> choose, int n, int k, vector<vector<int>> &points) {
    if (depth == n) {
        return check(choose, n, k, points);
    } else {
        for (int i = 0; i < k; i++) {
            vector<int> next_choose = choose;
            next_choose.push_back(i);
            if (recursive(depth + 1, next_choose, n, k, points)) {
                return true;
            }
        }
    }
    return false;
}

int main() {

    int n;
    int k;
    cin >> n;
    cin >> k;

    vector<vector<int>> points(n, vector<int>(k));
    rep(i, n) rep(j, k) cin >> points[i][j];

    bool b = recursive(0, vector<int>(0), n, k, points);
    if (b) {
        cout << "Found" << endl;
    } else {
        cout << "Nothing" << endl;
    }
}