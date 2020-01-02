#include <bits/stdc++.h>
#include <cmath>

using namespace std;
//typedef long long ll;
typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<char> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;

ll gcd(ll x, ll y) {
    if (x < y) swap(x, y);
    if (y == 0) {
        return x;
    }
    return gcd(y, x % y);
}

ll lcm(ll x, ll y) {
    return x * y / gcd(x, y);
}

int main() {
    ll n;
    cin >> n;

    ll t;
    ll a;
    cin >> t >> a;

    rep(i, n - 1) {
        ll ti, ai;
        cin >> ti >> ai;

        ll next_rate_1 = [&] {
            ll rate = (t + ti - 1) / ti;
            ll next_t = ti * rate;
            ll next_a = ai * rate;
            if (next_t >= t && next_a >= a) {
                return rate;
            }
            return INF;
        }();

        ll next_rate_2 = [&] {
            ll rate = (a + ai - 1) / ai;
            ll next_t = ti * rate;
            ll next_a = ai * rate;
            if (next_t >= t && next_a >= a) {
                return rate;
            }
            return INF;
        }();

        assert(!(next_rate_1 == INF && next_rate_2 == INF));

        ll next_rate = min(next_rate_1, next_rate_2);

        t = ti * next_rate;
        a = ai * next_rate;
    }

    cout << (t + a) << endl;

}
