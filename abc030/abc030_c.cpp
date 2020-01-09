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
const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
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
    ll n, m;
    ll x, y;

    cin >> n >> m >> x >> y;

    vector<ll> a_to_b(n);
    rep(i, n) cin >> a_to_b[i];
    vector<ll> b_to_a(n);
    rep(i, m)cin >> b_to_a[i];

    ll now = 0;
    ll count = 0;
    ll airport = 'a';

    while (true) {
        if (airport == 'a') {
            auto leave_i = lower_bound(a_to_b.begin(), a_to_b.end(), now);
            if (leave_i == a_to_b.end()) {
                break;
            }
            ll leave = *leave_i;
            airport = 'b';
            now = leave + x;
            count++;
        } else {
            auto leave_i = lower_bound(b_to_a.begin(), b_to_a.end(), now);
            if (leave_i == b_to_a.end()) {
                break;
            }
            ll leave = *leave_i;
            airport = 'a';
            now = leave + y;
            count++;
        }
    }

    cout << count / 2 << endl;
}
