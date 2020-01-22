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

vector<int> amida_simulator(vector<int> &horizontal, int width) {
    vector<int> currents(width);
    vector<int> current_indexes(width);
    rep(i, width) currents[i] = i;
    rep(i, width) current_indexes[i] = i;

    for (int h : horizontal) {
        int h1 = currents[h];
        int h2 = currents[h + 1];

        swap(current_indexes[h1], current_indexes[h2]);
        currents[h] = h2;
        currents[h + 1] = h1;

    }
    return current_indexes;
}


int main() {

    int n, m, d;
    cin >> n >> m >> d;

    assert(n <= 8);

    vector<int> horizontal(m);
    rep(i, m) {
        int a;
        cin >> a;
        a--;
        horizontal[i] = a;
    }
    vector<int> move_table = amida_simulator(horizontal, n);

    d %= n;
    vector<int> d_move_table(n);

    for (int i = 0; i < n; i++) {
        int now = move_table[i];
        for (int j = 0; j < d - 1; j++) {
            now = move_table[now];
        }
        d_move_table[i] = now;
    }

    rep(i, n) {
        cout << d_move_table[i] + 1 << endl;
    }

}