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


class MatrixSum {
    vector<vector<ll>> original;
    vector<vector<ll>> sum_table;

public:
    MatrixSum(vector<vector<ll>> &original) {
        this->original = original;
        this->sum_table = vector<vector<ll>>(original.size() + 1, vector<ll>(original[0].size() + 1));

        for (ll y = 1; y <= original.size(); y++) {
            ll xmax = original[y - 1].size();
            for (ll x = 1; x <= xmax; x++) {
                sum_table[y][x] += sum_table[y][x - 1];
                sum_table[y][x] += sum_table[y - 1][x];
                sum_table[y][x] -= sum_table[y - 1][x - 1];
                sum_table[y][x] += original[y - 1][x - 1];

            }
        }

    }

    void print() {

        for (ll y = 0; y < sum_table.size(); y++) {
            for (ll x = 0; x < sum_table[y].size(); x++) {
                printf("%02lld ", sum_table[y][x]);
            }
            cout << endl;
        }
        cout << endl;

        for (ll y = 0; y < original.size(); y++) {
            for (ll x = 0; x < original[y].size(); x++) {
                cout << range(y, x, 2, 2) << ' ';
            }
            cout << endl;
        }


    }


    ll range(ll start_y, ll start_x, ll height, ll width) {
        start_y %= original.size();
        start_x %= original[start_y].size();
        ll end_y = start_y + height - 1;
        ll enx_x = start_x + width - 1;

        if (end_y >= original.size() && enx_x >= original[start_y].size()) {
            ll now = 0;
            {
                // 左上
                ll p_start_y = 0;
                ll p_start_x = 0;
                ll p_height = end_y - original.size() + 1;
                ll p_width = enx_x - original[start_y].size() + 1;

//                now += segment(p_start_y, p_start_x, p_height, p_width);
                now += range(p_start_y, p_start_x + original.size(), p_height, p_width);
            }
            {
                // 右上
                ll p_start_y = 0;
                ll p_start_x = start_x;
                ll p_height = end_y - original.size() + 1;
                ll p_width = original[start_y].size() - start_x;

//                now += segment(p_start_y, p_start_x, p_height, p_width);
                now += range(p_start_y, p_start_x + original.size(), p_height, p_width);
            }
            {
                // 左下
                ll p_start_y = start_y;
                ll p_start_x = 0;
                ll p_height = original.size() - start_y;
                ll p_width = enx_x - original[start_y].size() + 1;

                now += segment(p_start_y, p_start_x, p_height, p_width);
            }
            {
                // 左下
                ll p_start_y = start_y;
                ll p_start_x = start_x;
                ll p_height = original.size() - start_y;
                ll p_width = original[start_y].size() - start_x;

                now += segment(p_start_y, p_start_x, p_height, p_width);
            }
            return now;
        } else if (end_y >= original.size()) {
            ll now = 0;
            {
                // 上
                ll p_start_y = 0;
                ll p_start_x = start_x;
                ll p_height = end_y - original.size() + 1;
                ll p_width = width;

//                now += segment(p_start_y, p_start_x, p_height, p_width);
                now += range(p_start_y, p_start_x + original.size(), p_height, p_width);
            }
            {
                // 下
                ll p_start_y = start_y;
                ll p_start_x = start_x;
                ll p_height = original.size() - start_y;
                ll p_width = width;

                now += segment(p_start_y, p_start_x, p_height, p_width);
            }
            return now;
        } else if (enx_x >= original[start_y].size()) {
            ll now = 0;
            {
                // 左
                ll p_start_y = start_y;
                ll p_start_x = 0;
                ll p_height = height;
                ll p_width = enx_x - original[start_y].size() + 1;

                ll n = segment(p_start_y, p_start_x, p_height, p_width);
                now += n;
            }
            {
                // 右
                ll p_start_y = start_y;
                ll p_start_x = start_x;
                ll p_height = height;
                ll p_width = original[start_y].size() - start_x;

                ll n = segment(p_start_y, p_start_x, p_height, p_width);
                now += n;
            }
            return now;
        } else {
            return segment(start_y, start_x, height, width);
        }
    }

    ll segment(ll start_y, ll start_x, ll height, ll width) {
        assert(start_y >= 0);
        assert(start_x >= 0);
        assert(start_y < original.size());
        assert(start_x < original[start_y].size());
        assert(start_y < height + original.size() - 1);
        assert(start_x < width + original[start_y].size() - 1);
        assert(height > 0);
        assert(width > 0);

        ll left_up_y = start_y;
        ll left_up_x = start_x;
        ll left_down_y = left_up_y + height - 1;
        ll left_down_x = start_x;
        ll right_up_y = start_y;
        ll right_up_x = start_x + width - 1;
        ll right_down_y = left_down_y;
        ll right_down_x = right_up_x;

//        printf(" (%lld %lld), (%lld %lld)\n (%lld %lld), (%lld %lld)\n\n",
//               left_up_y, left_up_x,
//               right_up_y, right_up_x,
//               left_down_y, left_down_x,
//               right_down_y, right_down_x
//        );

        ll sum = sum_table[right_down_y + 1][right_down_x + 1];
        ll ld = sum_table[left_down_y + 1][left_down_x];
        ll ru = sum_table[right_up_y][right_up_x + 1];
        ll lu = sum_table[left_up_y][left_up_x];

        return sum - ld - ru + lu;

    }


};

ll sum(vector<vector<ll>> &board, ll k, ll y, ll x) {
//    cout << y << ' ' << x << endl;

    x %= (2 * k);

    ll right_w = k + k - 1;
    ll down_w = k - 1;

    ll up_b = y;
    ll down_b = y + k - 1;
    ll left_b = x;
    ll right_b = x + k - 1;

    auto get_small_sum = [&](ll y, ll x) -> ll {

//        for (ll _y = 0; _y <= y + 1; _y++) {
//            for (ll _x = 0; _x <= x + 1; _x++) {
//                cout << board[_y][_x] << ' ';
//            }
//            cout << endl;
//        }

        assert(y + 1 < board.size());
        assert(x + 1 < board[y].size());
        ll cell_ll = board[y + 1][x + 1];

        ll left_sub = board[y + 1][max(x - k, 0ll)];
        ll up_sub = board[max(y - k, 0ll)][x + 1];
        ll lu_plus = board[max(y - k, 0ll)][max(x - k, 0ll)];


        cell_ll -= left_sub;
        cell_ll -= up_sub;
        cell_ll += lu_plus;

//        cout << cell_ll << endl;

        return cell_ll;
    };

    if (right_b <= right_w && down_b <= down_w) {
//        printf("y:%lld x:%lld (%lld,%lld)-(%lld,%lld) \n", y, x, y, x, down_b, right_b);
        return get_small_sum(down_b, right_b);
    }
    if (right_b > right_w && down_b > down_w) {
//        printf("y:%lld x:%lld (%lld,%lld)-(%lld,%lld) \n", y, x, y, x, down_w, right_w);
//        printf("y:%lld x:%lld (%lld,%lld)-(%lld,%lld) \n", y, x, 0ll, 0ll, down_b - down_w - 1, right_b - right_w - 1);

        ll a = get_small_sum(down_w, right_w);
        ll b = get_small_sum(down_b - down_w - 1, right_b - right_w - 1);
        return a + b;
    }
    if (right_b > right_w) {

//        printf("y:%lld x:%lld (%lld,%lld)-(%lld,%lld) \n", y, x, y, x, down_w, right_w);
//        printf("y:%lld x:%lld (%lld,%lld)-(%lld,%lld) \n", y, x, 0ll, 0ll, down_b - down_w - 1, right_b - right_w - 1);

        ll a = get_small_sum(down_b, right_w);
        ll b = get_small_sum(down_b, right_b - right_w - 1);
        return a + b;
    }
    if (down_b > down_w) {
        ll a = get_small_sum(down_w, right_b);
        ll b = get_small_sum(down_b - down_w - 1, right_b);
        return a + b;
    }
    throw -1;
}

int main() {

//    vector<vector<ll>> matrix = {
//            {1, 2, 3},
//            {4, 5, 6},
//            {7, 8, 9},
//    };
//



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

    MatrixSum black_sum(board_need_black);
    MatrixSum white_sum(board_need_white);

    ll black = black_sum.range(1, 1, k, k);
    ll white = white_sum.range(1, 1 + k, k, k);

    ll ans = 0;
    for (ll x = 0; x <= k * 2; x++) {
        for (ll y = 0; y <= k; y++) {
            ll black = black_sum.range(y, x, k, k);
            ll white = white_sum.range(y, x + k, k, k);
            ll now = black + white;
            cmax(ans, now);

        }
    }

    cout << ans << endl;

}