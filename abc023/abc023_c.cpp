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

    map<ll, ll> row_counts;
    map<ll, ll> column_counts;

    for (ll r : row) {
        row_counts[r]++;
    }
    for (ll c : column) {
        column_counts[c]++;
    }

    ll ans = 0;

    for (auto e : row_counts) {
        ll candy_count = e.first;
        ll row_cont = e.second;

        ll need = k - candy_count;
        ll column_count = column_counts[need];

        ans += (row_cont * column_count);
    }

    for (P candy : candies) {
        ll r = candy.first;
        ll c = candy.second;

        if (row[r] + column[c] == k) ans--;
        if (row[r] + column[c] == k + 1) ans++;
    }


    cout << ans << endl;
}
