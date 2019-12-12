#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
typedef pair<int, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = 10e15;
const ll MINF = -10e10;
//const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;

int main() {

    ll n;
    cin >> n;

    vector<ll> counter(5, 0);

    rep(i, n) {

        string s;
        cin >> s;
        switch (s[0]) {
            case 'M':
                counter[0]++;
                break;
            case 'A':
                counter[1]++;
                break;
            case 'R':
                counter[2]++;
                break;
            case 'C':
                counter[3]++;
                break;
            case 'H':
                counter[4]++;
                break;
        }
    }

    ll ans = 0;
    for (int x = 0; x < 5; x++) {
        for (int y = x + 1; y < 5; y++) {
            for (int z = y + 1; z < 5; z++) {
                ans += counter[x] * counter[y] * counter[z];
            }
        }
    }

    cout << ans << endl;

}