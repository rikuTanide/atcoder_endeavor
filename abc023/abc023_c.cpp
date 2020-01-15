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


    int max_r, max_c, k;
    cin >> max_r >> max_c >> k;
    int n;
    cin >> n;
    vector<P> candies(n);

    vector<int> row(max_r, 0);
    vector<int> column(max_c, 0);
    vector<int> row_index(max_r, 0);
    vector<int> column_index(max_c, 0);

    rep(i, n) {
        int r, c;
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
        }
        rep(i, max_c) {
            column[i] = column_sort[i].first;
            column_index[i] = column_sort[i].second;
        }

        sort(candies.begin(), candies.end());

    }

    auto has = [&](int i, int j_s, int j_e) {
        int oi = row_index[i];
        int ojs = column_index[j_s];
        int oje = column_index[j_e];

        auto start = lower_bound(candies.begin(), candies.end(), P(oi, ojs));
        auto end = upper_bound(candies.begin(), candies.end(), P(oi, oje));

        return end - start;
    };

    ll ans = 0;

    for (int ri = 0; ri < max_r; ri++) {
        int r = row[ri];
        auto start = lower_bound(column.begin(), column.end(), k - r);
        auto end = upper_bound(column.begin(), column.end(), k - r);
        int range = end - start;

        int s = start - column.begin();
        int e = end - column.begin();
        int has_candy = has(r, s, e);
        ans += range;
        ans -= has_candy;
    }

    for (int ri = 0; ri < max_r; ri++) {
        int r = row[ri];
        auto start = lower_bound(column.begin(), column.end(), k - r + 1);
        auto end = upper_bound(column.begin(), column.end(), k - r + 1);

        int s = start - column.begin();
        int e = end - column.begin();
        int has_candy = has(r, s, e);
        ans += has_candy;
    }

    cout << ans << endl;

}
