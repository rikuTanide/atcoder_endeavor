#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<int> &o) {
    int a;
    in >> a;
    o.insert(a);
    return in;
}

std::istream &operator>>(std::istream &in, queue<int> &o) {
    ll a;
    in >> a;
    o.push(a);
    return in;
}

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

class Conv {
    ll cursor = 0;
    map<ll, ll> to_short; // <original, small >
    map<ll, ll> to_long; // <small, original>
    std::set<ll> tmp;


public:
    void set(ll original) {
        if (to_short.find(original) != to_short.end()) {
            return;
        }
        to_long[cursor] = original;
        to_short[original] = cursor;
        cursor++;
    }

    ll revert(ll after) {
        assert(to_long.find(after) != to_long.end());
        return to_long[after];
    }

    ll convert(ll original) {
        assert(to_short.find(original) != to_short.end());
        return to_short[original];
    }

    ll next() {
        return cursor;
    }

    // 前計算省略のため
    void cache(ll t) {
        tmp.insert(t);
    }

    void build() {
        for (ll t : tmp) {
            set(t);
        }
    }

};


int main() {
    int n, color_count, comb_bonus, complete_bonus;
    cin >> n >> color_count >> comb_bonus >> complete_bonus;


    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(color_count, vector<ll>(1 << color_count, -INF)));
    dp[0][0][0] = 0;

    Conv conv;

    auto color_points = [&]() -> vector<ll> {
        vector<P> _colors(color_count);
        for (P &p:_colors) {
            char c;
            int point;
            cin >> c >> point;
            p.first = int(c - 'A');
            p.second = point;
        }

        for (P p : _colors) conv.cache(p.first);
        conv.build();

        vector<ll> color_points(color_count);
        for (P p : _colors) color_points[conv.convert(p.first)] = p.second;
        return color_points;
    }();


    string s;
    cin >> s;
    vector<int> blocks(n);
    rep(i, n) blocks[i] = conv.convert(s[i] - 'A');

    auto set = [&](int i, int last_color, int before_pattern, ll value) {
        int next_pattern = before_pattern | (1 << last_color);
        ll pb = next_pattern != before_pattern && next_pattern == ((1 << color_count) - 1) ? complete_bonus : 0;
        ll nv = value + pb;
        cmax(dp[i][last_color][next_pattern], nv);
    };

    rep(i, n) {
        int block = blocks[i];
        int color_point = color_points[block];

        rep(prev_block_color, color_count) {
            rep(before_pattern, 1 << color_count) {
                ll prev = dp[i][prev_block_color][before_pattern];

                if (before_pattern != 0 && block == prev_block_color) {
                    set(
                            i + 1,
                            block,
                            before_pattern,
                            prev + color_point + comb_bonus
                    );
                } else {
                    set(
                            i + 1,
                            block,
                            before_pattern,
                            prev + color_point
                    );
                }

                cmax(dp[i + 1][prev_block_color][before_pattern], prev);
            }
        }

    }
    ll ans = -INF;
    rep(last_color, color_count) {
        rep(pattern, 1 << color_count) {
            cmax(ans, dp[n][last_color][pattern]);
        }
    }

    cout << ans << endl;

}
