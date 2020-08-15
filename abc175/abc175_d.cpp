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

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> ps(n);
    rep(i, n) cin >> ps[i], ps[i]--;
    vector<ll> cs(n);
    rep(i, n) cin >> cs[i];

    vector<vector<ll>> dp(n, vector<ll>(2 * n));

    auto setup = [&](int i) {
        vector<ll> tmp(2 * n + 1);

        int now = i;
        ll ans = 0;
        rep(j, 2 * n) {
            now = ps[now];
            ans += cs[now];
            tmp[j + 1] = ans;
        }
        dp[i] = tmp;

    };

    rep(i, n)setup(i);

    if (k < 2 * n) {
        ll ans = -INF;
        rep(i, n) {
            ll now = *max_element(dp[i].begin() + 1, dp[i].begin() + k + 1);
            cmax(ans, now);
        }
        cout << ans << endl;
        ret();
    }

//    vector<int> start_loop_lens(n);
//    vector<int> start_loop_ids(n);
    vector<int> loop_lens(n);

    auto find_loop = [&](int i) {
//        int start_loop_len;
//        int start_loop_id;
        int loop_len;

//        {
//            unordered_set<int> used;
//            int now = i;
//            while (true) {
//                if (used.find(now) != used.end()) {
//                    start_loop_id = now;
//                    break;
//                }
//                used.insert(now);
//                now = ps[now];
//            }
//        }
//
//        {
//            start_loop_len = 0;
//            int now = i;
//            while (true) {
//                if (now == start_loop_id) break;
//                now = ps[now];
//                start_loop_len++;
//            }
//        }

        {
            loop_len = 0;
            int now = i;
            while (true) {
                now = ps[now];
                loop_len++;
                if (now == i) break;
            }
        }

//        start_loop_ids[i] = start_loop_id;
//        start_loop_lens[i] = start_loop_len;
        loop_lens[i] = loop_len;
    };

    rep(i, n) find_loop(i);

    vector<ll> can_loop(n);
    rep(i, n) can_loop[i] = k / loop_lens[i];
    vector<ll> loop_term(n);
    rep(i, n) loop_term[i] = max(0ll, can_loop[i] - 1);
    vector<ll> loop_end_scores(n);
    rep(i, n) loop_end_scores[i] = loop_term[i] * dp[i][k % loop_lens[i]];
    vector<ll> mod_scores(n);
    rep(i, n) mod_scores[i] = *max_element(dp[i].begin(), dp[i].begin() + k % loop_lens[i] + k % loop_lens[i] + 1);

    vector<ll> max_scores(n);
    rep(i, n) {
        ll ans = -INF;
        ll now = *max_element(dp[i].begin() + 1, dp[i].end());
        cmax(ans, now);
        ll loop_ans = loop_end_scores[i] + mod_scores[i];
        cmax(ans, loop_ans);
        max_scores[i] = ans;
    }
    ll ans = *max_element(max_scores.begin(), max_scores.end());

    cout << ans << endl;

}
