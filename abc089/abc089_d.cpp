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
const ll INF = 10e15;
const ll MINF = -10e10;
//const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;

int main() {
    ll h, w, d;

    cin >> h >> w >> d;

    vector<P> board(h * w);

    rep(y, h) {
        rep(x, w) {
            int a;
            cin >> a;
            a--;
            board[a] = P(x, y);
        }
    }
    ll max_step = h * w / d;
    vector<vector<ll>> move_mp(d, vector<ll>(max_step, 0));

    for (ll i = 0; i <= h * w - d; i++) {
        ll da = i % d;
        ll p = i / d;
        assert(p * d + da == i);
        P before = board[i];
        if (i + d >= h * w) break;
        P next = board[i + d];
        move_mp[da][p] = abs(before.first - next.first) + abs(before.second - next.second);
    }

    vector<vector<ll>> move_sum(d, vector<ll>(max_step + 1, 0));
    for (ll da = 0; da < move_mp.size(); da++) {
        vector<ll> mmp = move_mp[da];
        for (ll p = 0; p < mmp.size(); p++) {
            move_sum[da][p + 1] = move_sum[da][p] + mmp[p];
        }
    }

    ll q;
    cin >> q;

    rep(i, q) {
        ll l, r;
        cin >> l >> r;

        l--;
        r--;

        ll l_da = l % d;
        ll l_p = l / d;

        ll r_da = r % d;
        ll r_p = r / d;

        ll now = move_sum[r_da][r_p] - move_sum[l_da][l_p];
        cout << now << endl;

    }

}