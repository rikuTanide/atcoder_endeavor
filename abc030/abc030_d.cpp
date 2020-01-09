#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <cmath>

using namespace std;
//typedef long long ll;
typedef unsigned long long ll;
namespace mp = boost::multiprecision;

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
    ll n, a;
    mp::cpp_int k;
    cin >> n >> a >> k;
    a--;

    vector<ll> references(n);
    vector<ll> position(n, 0);
    vector<bool> visited(n, false);
    rep(i, n) cin >> references[i];
    rep(i, n) references[i]--;
    ll now = a;
    ll count = 0;

    while (true) {
        if (visited[now]) break;
        position[count] = references[now];
        visited[now] = true;
        count++;
        now = references[now];
    }

    count--;

    ll loop_start = now;
    ll loop_length = 0;
    vector<ll> loop_position(n, 0);
    while (true) {
        loop_position[loop_length] = now;
        loop_length++;
        if (references[now] == loop_start) {
            break;
        }
        now = references[now];
    }

    if (k <= count) {
        ll ik = static_cast<ll>(k);
        cout << position[ik - 1] + 1 << endl;
    } else {
        mp::cpp_int kk = k - count;
        kk--;
        kk %= loop_length;
        ll ik = static_cast<ll>(kk);

        cout << loop_position[ik] + 1 << endl;
    }

}
