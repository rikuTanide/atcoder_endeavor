#include <bits/stdc++.h>
#include <cmath>

//using namespace boost::multiprecision;
using namespace std;
typedef long long ll;
//typedef unsigned long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
typedef pair<int, int> P;
//typedef pair<ll, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX / 100;
//const ll INF = (1ll << 31) - 1;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
//typedef pair<int, int> P;
//typedef pair<double, double> P;
#define ret() return 0;

bool contain(set<string> &s, string a) { return s.find(a) != s.end(); }

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
const int mod = 1000000007;
//const ll mod = 1e10;
typedef priority_queue<long long, vector<long long>, greater<long long> > PQ_ASK;


int main() {
    int n;
    cin >> n;
    vector<ll> spots(n);
    rep(i, n) cin >> spots[i];
    vector<ll> costs(n + 1);
    ll sum = 0;

    auto get_cost = [&](int start, int end) {
        if (start == -1) return abs(spots[end]);
        if (end == n) return abs(spots[start]);
        return abs(spots[start] - spots[end]);
    };

    rep(i, n + 1) {
        ll cost = get_cost(i - 1, i);
        costs[i] = cost;
        sum += cost;
    }

    rep(i, n) {
        ll prev_cost = costs[i];
        ll next_cost = costs[i + 1];
        ll direct_cost = get_cost(i - 1, i + 1);

        ll now = sum - prev_cost - next_cost + direct_cost;
        cout << now << endl;
    }
}

