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
//const ll INF = 10e15;
const ll MINF = -10e10;
const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<vector<ll>> board_need_white(k, vector<ll>(k * 2, 0));
    vector<vector<ll>> board_need_black(k, vector<ll>(k * 2, 0));

    rep(i, n) {
        ll x, y;
        char c;
        cin >> x >> y >> c;
        x %= (2 * k);
        y %= (2 * k);

        if (x >= k && y >= k) {
            x -= k;
            y -= k;
        } else if (y >= k) {
            y -= k;
            x += k;
        }

        if (c == 'B') {
            board_need_black[y][x]++;
        } else {
            board_need_white[y][x]++;
        }
    }


    vector<vector<ll>> board_need_white_sum(k + 1, vector<ll>(k * 2 + 1, 0));
    vector<vector<ll>> board_need_black_sum(k + 1, vector<ll>(k * 2 + 1, 0));

    for (ll x = 1; x <= k * 2; x++) {
        for (ll y = 1; y <= k; y++) {
            board_need_black_sum[y][x] += board_need_black_sum[y][x - 1];
            board_need_black_sum[y][x] += board_need_black_sum[y - 1][x];
            board_need_black_sum[y][x] -= board_need_black_sum[y - 1][x - 1];
            board_need_black_sum[y][x] += board_need_black[y - 1][x - 1];

            board_need_white_sum[y][x] += board_need_white_sum[y][x - 1];
            board_need_white_sum[y][x] += board_need_white_sum[y - 1][x];
            board_need_white_sum[y][x] -= board_need_white_sum[y - 1][x - 1];
            board_need_white_sum[y][x] += board_need_white[y - 1][x - 1];
        }
    }

    vector<vector<ll>> board_need_white_dq(k * 2 + 1, vector<ll>(k * 4 + 1, 0));
    vector<vector<ll>> board_need_black_dq(k * 2 + 1, vector<ll>(k * 4 + 1, 0));

    for (ll x = 0; x < 2 * k; x++) {
        for (ll y = 0; y < k; y++) {
            board_need_white_dq[y + 1][x + 1] = board_need_white_sum[y + 1][x + 1];
            board_need_white_dq[y + 1 + k][x + 1] = board_need_white_sum[y + 1][x + 1] + board_need_white_sum[k][x + 1];
            board_need_white_dq[y + 1][x + 1 + k + k] =
                    board_need_white_sum[y + 1][x + 1] + board_need_white_sum[y + 1][k + k];


            board_need_black_dq[y + 1][x + 1] = board_need_black_sum[y + 1][x + 1];
            board_need_black_dq[y + 1 + k][x + 1] = board_need_black_sum[y + 1][x + 1] + board_need_black_sum[k][x + 1];
            board_need_black_dq[y + 1][x + 1 + k + k] =
                    board_need_black_sum[y + 1][x + 1] + board_need_black_sum[y + 1][k + k];

        }
    }
    for (ll x = 0; x < 2 * k; x++) {
        for (ll y = 0; y < k; y++) {
            board_need_black_dq[y + 1 + k][x + 1 + k + k] =
                    board_need_black_dq[y + k][x + 1 + k + k]
                    + board_need_black_dq[y + 1 + k][x + k + k]
                    - board_need_black_dq[y + k][x + k + k];
        }
    }

    for (ll x = 0; x < 2 * k; x++) {
        for (ll y = 0; y < k; y++) {
            board_need_white_dq[y + 1 + k][x + 1 + k + k] =
                    board_need_white_dq[y + k][x + 1 + k + k]
                    + board_need_white_dq[y + 1 + k][x + k + k]
                    - board_need_white_dq[y + k][x + k + k];
        }
    }

/*
    for (ll y = 0; y <= (k + k); y++) {
        for (ll x = 0; x <= 2 * (k + k); x++) {
            cout << board_need_white_dq[y][x] << ' ';
        }
        cout << endl;
    }
    cout << endl;

    for (ll y = 0; y <= (k + k); y++) {
        for (ll x = 0; x <= 2 * (k + k); x++) {
            cout << board_need_black_dq[y][x] << ' ';
        }
        cout << endl;
    }
    cout << endl;
*/

    ll ans = 0;

    for (ll x = 0; x <= 2 * k; x++) {
        for (ll y = 0; y <= k; y++) {
            ll black = board_need_black_dq[y + k][x + k];
            black += board_need_black_dq[y][x];
            black -= board_need_black_dq[y + k][x];
            black -= board_need_black_dq[y][x + k];

            ll white = board_need_white_dq[y + k][x + k + k];
            white += board_need_white_dq[y][x + k];
            white -= board_need_white_dq[y + k][x + k];
            white -= board_need_white_dq[y][x + k + k];

//            cout << white << ' ' << black << ' ' << white + black << endl;

            ll now = black + white;
            cmax(ans, now);

        }
    }

    cout << ans << endl;

}