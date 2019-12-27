#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;
    vector<P> students(n);
    rep(i, n) {
        cin >> students[i].first;
        cin >> students[i].second;
    }

    vector<P> checkpoints(m);
    rep(i, m) {
        cin >> checkpoints[i].first;
        cin >> checkpoints[i].second;
    }

    for (P p : students) {

        ll max_distance = INF;
        ll max_index = 0;

        for (int i = 0; i < m; i++) {
            P c = checkpoints[i];
            ll h = abs(p.first - c.first);
            ll w = abs(p.second - c.second);
            ll distance = h + w;
            if (distance < max_distance) {
                max_index = i;
                max_distance = distance;
            }
        }

        cout << max_index + 1 << endl;

    }


}

