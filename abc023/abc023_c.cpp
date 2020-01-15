#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX;
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

int main() {


    ll max_r, max_c, k;
    cin >> max_r >> max_c >> k;
    ll n;
    cin >> n;
    vector<P> candies(n);

    vector<ll> row(max_r, 0);
    vector<ll> column(max_c, 0);
    vector<ll> row_index(max_r, 0);
    vector<ll> row_rev_index(max_r, 0);
    vector<ll> column_index(max_c, 0);
    vector<ll> column_rev_index(max_c, 0);

    rep(i, n) {
        ll r, c;
        cin >> r >> c;
        r--;
        c--;
        row[r]++;
        column[c]++;
        candies[i].first = r;
        candies[i].second = c;
    }

    {
        vector<P> row_sort(max_r);
        vector<P> column_sort(max_c);
        rep(i, max_r) {
            row_sort[i].first = row[i];
            row_sort[i].second = i;
        }
        rep(i, max_c) {
            column_sort[i].first = column[i];
            column_sort[i].second = i;
        }
        sort(row_sort.begin(), row_sort.end());
        sort(column_sort.begin(), column_sort.end());

        rep(i, max_r) {
            row[i] = row_sort[i].first;
            row_index[i] = row_sort[i].second;
            row_rev_index[row_sort[i].second] = i;
        }
        rep(i, max_c) {
            column[i] = column_sort[i].first;
            column_index[i] = column_sort[i].second;
            column_rev_index[column_sort[i].second] = i;
        }

        rep(i, n) {
            candies[i].first = row_rev_index[candies[i].first];
            candies[i].second = column_rev_index[candies[i].second];
        }

        sort(candies.begin(), candies.end());

    }

    auto has = [&](ll i, ll j_s, ll j_e) {
        ll oi = row_index[i];
        auto start = lower_bound(candies.begin(), candies.end(), P(oi, j_s));
        auto end = upper_bound(candies.begin(), candies.end(), P(oi, j_e));
        ll ans = end - start;
        return ans;
    };

    ll ans = 0;

    for (ll ri = 0; ri < max_r; ri++) {
        ll r = row[ri];
        auto start = lower_bound(column.begin(), column.end(), k - r);
        auto end = upper_bound(column.begin(), column.end(), k - r);
        ll range = end - start;

        ll s = start == column.end() ? INF : start - column.begin();
        ll e = end == column.end() ? INF : end - column.begin();
        ll has_candy = has(r, s, e);
        ans += range;
        ans -= has_candy;
    }

    for (ll ri = 0; ri < max_r; ri++) {
        ll r = row[ri];
        auto start = lower_bound(column.begin(), column.end(), k - r + 1);
        auto end = upper_bound(column.begin(), column.end(), k - r + 1);

        ll s = start == column.end() ? INF : start - column.begin();
        ll e = end == column.end() ? INF : end - column.begin();
        ll has_candy = has(r, s, e);
        ans += has_candy;
    }

    cout << ans << endl;

}
