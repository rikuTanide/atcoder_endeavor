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

int amida_simulator(int start, vector<int> &horizontal, int height) {
    int now = start;
    for (int i = 0; i < height; i++) {
        int bar = horizontal[i];
        if (now == bar) {
            now++;
        } else if (now == bar + 1) {
            now--;
        }
    }
    return now;
}

int main() {

    int n, m, d;
    cin >> n >> m >> d;

    assert(d == 1);

    vector<int> horizontal(m);
    rep(i, m) {
        int a;
        cin >> a;
        a--;
        horizontal[i] = a;
    }

    rep(i, n) {
        cout << amida_simulator(i, horizontal, m) + 1 << endl;
    }

}