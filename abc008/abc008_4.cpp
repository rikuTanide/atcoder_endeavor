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

struct Machine {
    int x, y;
};

int check(vector<Machine> &machines, int w, int h) {
    vector<vector<bool>> golds(w, vector<bool>(h, true));
    int ans = 0;
    for (Machine &machine : machines) {
        golds[machine.x][machine.y] = false;
        ans++;
        // 上
        for (int y = machine.y + 1; y < h; y++) {
            if (!golds[machine.x][y]) break;
            golds[machine.x][y] = false;
            ans++;
        }
        // 下
        for (int y = machine.y - 1; y >= 0; y--) {
            if (!golds[machine.x][y]) break;
            golds[machine.x][y] = false;
            ans++;
        }

        // 右
        for (int x = machine.x + 1; x < w; x++) {
            if (!golds[x][machine.y]) break;
            golds[x][machine.y] = false;
            ans++;
        }

        // 左
        for (int x = machine.x - 1; x >= 0; x--) {
            if (!golds[x][machine.y]) break;
            golds[x][machine.y] = false;
            ans++;
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
        machine.x--;
        machine.y--;
        machines.push_back(machine);
    }


    vector<int> indexes(n);
    rep(i, n) indexes[i] = i;


    int ans = 0;
    do {
        vector<Machine> ordered_machines(n);
        for (int i : indexes) {
            ordered_machines[i] = machines[indexes[i]];
        }
        int now = check(ordered_machines, w, h);
        cmax(ans, now);
        if (now == 119) {
            cout << endl;
        }
    } while (next_permutation(indexes.begin(), indexes.end()));
    cout << ans << endl;
}
