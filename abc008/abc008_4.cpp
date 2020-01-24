#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
//typedef pair<ll, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX / 100;
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
// https://atcoder.jp/contests/abc008/submissions/9264344
// なんもわからん。

typedef tuple<ll, ll, ll, ll> square;
struct Machine {
    ll x, y;
};

ll search(
        ll x1, ll y1, ll x2, ll y2,
        vector<Machine> &machines,
        map<square, ll> &memo) {
    square s(x1, y1, x2, y2);
    if (memo.find(s) != memo.end()) return memo[s];
    ll ans = 0;
    ll c = (x2 - x1) + (y2 - y1) + 1;
    for (Machine &machine : machines) {
        if (x1 <= machine.x && machine.x <= x2 && y1 <= machine.y && machine.y <= y2) {
            ll now = c + search(x1, y1, machine.x - 1, machine.y - 1, machines, memo) +
                      search(x1, machine.y + 1, machine.x - 1, y2, machines, memo) +
                      search(machine.x + 1, y1, x2, machine.y - 1, machines, memo) +
                      search(machine.x + 1, machine.y + 1, x2, y2, machines, memo);
            cmax(ans, now);
        }
    }
    memo[s] = ans;
    return ans;
}

int main() {
    ll w, h, n;
    cin >> w >> h >> n;
    vector<Machine> machines;
    rep(i, n) {
        Machine machine;
        cin >> machine.x;
        cin >> machine.y;
        machines.push_back(machine);
    }

    map<square, ll> memo;
    cout << search(1, 1, w, h, machines, memo) << endl;

}