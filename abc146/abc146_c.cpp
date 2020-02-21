#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
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

int digits(ll n) {
    return log10(n) + 1;
}

bool check(ll n, ll x, ll a, ll b) {
    ll an = a * n, bd = b * digits(n);
    ll now = an + bd;
    return x >= now;
}

int main() {


    ll a, b, x;
    cin >> a >> b >> x;

    if (!check(1, x, a, b)) {
        cout << 0 << endl;
        return 0;
    }
    ll ma = 1000000000ll;
    if (check(ma, x, a, b)) {
        cout << ma << endl;
        return 0;
    }

    ll floor = 1;
    ll ceil = ma;

    while (floor + 1 < ceil) {
        ll mid = (floor + ceil) / 2;
        bool ok = check(mid, x, a, b);

        if (ok) {
            floor = mid;
        } else {
            ceil = mid;
        }

    }


    cout << floor << endl;
}


