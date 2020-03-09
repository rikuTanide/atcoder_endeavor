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

int check(vector<int> &board, int i, int j, int n) {
    int ans = 0;
    for (int k = 0; k < n; k++) {
        int c = k % 2 == 0 ? i : j;
        if (board[k] != c) ans++;
    }
    return ans;
}

int main() {
    int n, c;
    cin >> n >> c;

    vector<int> board(n);
    rep(i, n) cin >> board[i];

    int ans = INT_MAX;
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            if (i == j) continue;
            int now = check(board, i, j, n);
            cmin(ans, now);

        }
    }
    cout << ans * c << endl;

}
