#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
//typedef long long ll;
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = 10e15;
const ll MINF = -10e10;
const int INF = INT_MAX / 100;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("~/Downloads/02.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;
// https://atcoder.jp/contests/abc008/submissions/9264344
// なんもわからん。

typedef tuple<int, int, int, int> square;
struct Machine {
    int x, y;
};

int search(
        int x1, int y1, int x2, int y2,
        vector<Machine> &machines,
        map<square, int> &memo) {
    square s(x1, y1, x2, y2);
    if (memo.find(s) != memo.end()) return memo[s];
    int ans = 0;
    int c = (x2 - x1) + (y2 - y1) + 1;
    for (Machine &machine : machines) {
        if (x1 <= machine.x && machine.x <= x2 && y1 <= machine.y && machine.y <= y2) {
            int now = c + search(x1, y1, machine.x - 1, machine.y - 1, machines, memo) +
                      search(x1, machine.y + 1, machine.x - 1, y2, machines, memo) +
                      search(machine.x + 1, y1, x2, machine.y - 1, machines, memo) +
                      search(machine.x + 1, machine.y + 1, x2, y2, machines, memo);
            cmax(ans, now);
        }
    }
    return ans;
}

int main() {
    int w, h, n;
    cin >> w >> h >> n;
    assert(n <= 8);
    vector<Machine> machines;
    rep(i, n) {
        Machine machine;
        cin >> machine.x;
        cin >> machine.y;
        machines.push_back(machine);
    }

    map<square, int> memo;
    cout << search(1, 1, w, h, machines, memo) << endl;

}
