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
//typedef pair<ll, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX / 100;
//const ll INF = (1ll << 31) - 1;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
//typedef pair<int, int> P;
//typedef pair<double, double> P;

//bool contain(set<P> &s, P a) { return s.find(a) != s.end(); }

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
const int mod = 1000000007;
typedef priority_queue<long long, vector<long long>, greater<long long> > PQ_ASK;

double distance(double x1, double y1, double x2, double y2) {
    ll x = x1 - x2;
    ll y = y1 - y2;
    ll xx = x * x;
    ll yy = y * y;
    ll sum = xx + yy;
    return sqrt(sum);
}

int main() {
    double txa, tya, txb, tyb, t, v;
    cin >> txa >> tya >> txb >> tyb >> t >> v;
    int n;
    cin >> n;
    double possible_distance = t * v;
    rep(i, n) {
        double x, y;
        cin >> x >> y;

        double total_distance = distance(x, y, txa, tya) + distance(x, y, txb, tyb);
        if (possible_distance >= total_distance - EPS) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}
