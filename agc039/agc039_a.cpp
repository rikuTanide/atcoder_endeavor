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
//typedef pair<int, int> P;
//typedef pair<ll, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX / 100;
//const ll INF = (1ll << 31) - 1;
//const ll INF = 1e15;
//const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
//typedef pair<int, int> P;
//typedef pair<double, double> P;
#define ret() return 0;

bool contain(set<char> &s, char a) { return s.find(a) != s.end(); }

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
const int mod = 1000000007;
//const ll mod = 1e10;
typedef priority_queue<long long, vector<long long>, greater<long long> > PQ_ASK;

struct R {
    char c;
    int r;
};

int main() {

    string s;
    ll k;
    cin >> s >> k;

    vector<R> v;
    for (char c : s) {
        if (v.empty())v.push_back({c, 1});
        else if (v.back().c == c)v.back().r++;
        else v.push_back({c, 1});
    }
    ll ans = 0;
    for (R r : v) ans += (r.r / 2);
    ans *= k;
    if (v.front().c == v.back().c && v.front().r != s.size()) {
        int a = v.front().r;
        int b = v.back().r;

        int a2 = a / 2;
        int b2 = b / 2;
        int ab2 = (a + b) / 2;

        int d = a2 + b2 - ab2;
        ll j = (k - 1) * d;
        ans -= j;
    }
    cout << ans << endl;
}


