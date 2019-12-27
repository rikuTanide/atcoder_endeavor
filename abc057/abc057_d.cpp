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
const ll INF = LONG_LONG_MAX;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
//const int mod = 1000000007;
const ll mod = INF / 1000;


vector<pair<ll, int >> factorize(ll n) {
    vector<pair<ll, int >> res;

    for (ll i = 2; i * i <= n; i++) {
        if (n % i != 0) {
            continue;
        }
        res.emplace_back(i, 0);
        while (n % i == 0) {
            n /= i;
            res.back().second++;
        }
    }

    if (n != 1) res.emplace_back(n, 1);
    return res;

}

ll comb(ll l, ll r) {
    vector<ll> factors(50);
    for (ll j = l; j > (l - r); j--) {
        auto fs = factorize(j);
        for (auto f : fs) {
            factors[f.first] += f.second;
        }
    }

    for (ll j = 1; j <= r; j++) {
        auto fs = factorize(j);
        for (auto f : fs) {
            factors[f.first] -= f.second;
        }
    }

    ll s =1;

    for(int j = 1 ; j < 50; j ++ ) {
        for(int k = 0 ; k < factors[j]; k ++) {
            s *= j;
        }
    }

    return s;

}

int main() {
    ll n, a, b;
    cin >> n >> a >> b;

    vector<ll> values(n);
    rep(i, n) cin >> values[i];

    sort(values.rbegin(), values.rend());
    ll min_element = values[a - 1];
    ll min_element_count = accumulate(values.begin(), values.end(), 0ll, [&](ll m, ll n) {
        if (n == min_element) return m + 1;
        return m;
    });

    ll large_element_count = accumulate(values.begin(), values.end(), 0ll, [&](ll m, ll n) {
        if (n > min_element) return m + 1;
        return m;
    });

    ll can_choose = [&] {
        return min(b - large_element_count, min_element_count);
    }();

    ll need_choose = [&] {
        return a - large_element_count;
    }();

    if (values[0] == min_element) {

        ll ans = 0;
        for (ll i = need_choose; i <= can_choose; i++) {
            ll now = comb(min_element_count, i);
            ans += now;
        }

        cout << ans << endl;
    } else {
        ll ans = comb(min_element_count, need_choose);
        cout << ans << endl;

    }
}
