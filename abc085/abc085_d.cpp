#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = 10e15;
const ll MINF = -10e10;
const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;

int main() {

    ll n, h;
    cin >> n >> h;

    vector<ll> sword_slices(n);
    vector<ll> sword_throws(n);
    rep(i, n) {
        cin >> sword_slices[i];
        cin >> sword_throws[i];
    }

    ll slice_max = *max_element(sword_slices.begin(), sword_slices.end());
    ll throw_sum = accumulate(sword_throws.begin(), sword_throws.end(), 0ll, [&](ll a, ll b) -> ll {
        if (b >= slice_max) {
            return a + b;
        } else {
            return a;
        }
    });

    ll throw_count = accumulate(sword_throws.begin(), sword_throws.end(), 0ll, [&](ll a, ll b) -> ll {
        if (b >= slice_max) {
            return a + 1;
        } else {
            return a;
        }
    });

    h -= throw_sum;
    if (h < 0) {
        cout << throw_count << endl;
        return 0;
    }

    ll slice_count = (h + slice_max - 1) / slice_max;

    cout << throw_count + slice_count << endl;

}