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

bool contain(set<string> &s, string a) { return s.find(a) != s.end(); }

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
const int mod = 1000000007;
typedef priority_queue<long long, vector<long long>, greater<long long> > PQ_ASK;

struct Plain {
    ll arrival, leave;
};


int main() {
    int n;
    cin >> n;

    ll c, k;
    cin >> c >> k;
    vector<Plain> tmp;

    rep(i, n) {
        ll t;
        cin >> t;
        Plain plain{t, t + k};
        tmp.push_back(plain);
    }
    sort(tmp.begin(), tmp.end(), [](Plain p, Plain q) { return p.arrival < q.arrival; });

    queue<Plain> plains;
    for (Plain p : tmp) plains.push(p);

    ll ans = 0;
    while (!plains.empty()) {
        ll last = plains.front().leave;
        ll passengers = 0;
        while (!plains.empty() && plains.front().arrival <= last && passengers < c) {
            plains.pop();
            passengers++;
        }
        ans++;
    }
    cout << ans << endl;

}


