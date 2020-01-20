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

bool contain(set<char> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;

struct Remain {
    int start, end, point;
};

int main() {

    int n, m;
    cin >> n >> m;

    vector<Remain> remains(n);
    rep(i, n) {
        int l, r, s;
        cin >> l >> r >> s;
        l--;
        r--;
        Remain remain = {l, r, s};
        remains[i] = remain;
    }
    vector<ll> start_sum(m);
    vector<ll> end_sum(m);

    for (Remain remain : remains) {
        start_sum[remain.start] += remain.point;
        end_sum[remain.end] += remain.point;
    }

    for (int i = 1; i < m; i++) {
        end_sum[i] += end_sum[i - 1];
    }

    for (int i = m - 2; i >= 0; i--) {
        start_sum[i] += start_sum[i + 1];
    }

    ll ans = 0;
    for (int i = 0; i < m; i++) {
        int e = i - 1;
        int s = i + 1;
        ll now = 0;
        if (e >= 0) {
            now += end_sum[e];
        }
        if (s < m) {
            now += start_sum[s];
        }
        cmax(ans, now);
    }
    cout << ans << endl;

}

