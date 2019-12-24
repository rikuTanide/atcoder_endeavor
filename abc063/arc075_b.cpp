#include <bits/stdc++.h>
#include <cmath>

#include <assert.h>    // LON
#include <math.h>    // sqrt()


using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX;
const ll MINF = -10e10;
const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;

bool check(vector<ll> ghosts, ll i, ll a, ll b) {
    ll minus = b * i;
    ll diff = a - b;

    for (int j = 0; j < ghosts.size(); j++) {
        ghosts[j] -= minus;
    }

    ll count = 0;

    for (ll k : ghosts) {
        if (k <= 0) continue;
        count += ((k + diff - 1) / diff);
    }
    return count <= i;

}

int main() {
    ll n, a, b;
    cin >> n >> a >> b;

    vector<ll> originals(n);


    rep(i, n) {
        cin >> originals[i];
    }

    ll floor = [&] {
        ll sum = accumulate(originals.begin(), originals.end(), 0ll);

        ll zako = b * (n - 1);
        ll tsuyo = a;
        ll ikkai = zako + tsuyo;

        return max(sum / ikkai - 1, 1ll);
    }();
    ll ceil = [&] {
        ll sum = accumulate(originals.begin(), originals.end(), 0ll);
        return sum / b + 1;
    }();

    while (floor + 1 < ceil) {
        ll mid = (floor + ceil) / 2;
        if (check(originals, mid, a, b)) {
            ceil = mid;
        } else {
            floor = mid;
        }
    }

    cout << ceil << endl;

}