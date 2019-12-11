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

vector<ll> listMod(vector<ll> &list, ll m2) {
    vector<ll> res(list.size());
    rep(i, list.size()) {
        res[i] = list[i] % m2;
    }
    sort(res.begin(), res.end());
    return res;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> as(n);
    vector<ll> bs(n);
    rep(i, n) {
        cin >> as[i];
    }
    rep(i, n) {
        cin >> bs[i];
    }

    ll ans = 0;

    for (int i = 0; i < 30; i++) {
        ll mod2 = 1LL << (i + 1);
        vector<ll> mod_as = listMod(as, mod2);
        vector<ll> mod_bs = listMod(bs, mod2);
        ll t = 1LL << i;

        ll now = 0;
        for (ll a  : mod_as) {
            ll t1 = t - a;
            ll t2 = 2 * t - a;
            ll t3 = 3 * t - a;
            ll t4 = 4 * t - a;

            auto l1 = lower_bound(mod_bs.begin(), mod_bs.end(), t1);
            auto r1 = lower_bound(mod_bs.begin(), mod_bs.end(), t2);
            auto l2 = lower_bound(mod_bs.begin(), mod_bs.end(), t3);
            auto r2 = lower_bound(mod_bs.begin(), mod_bs.end(), t4);
            now += (r1 - l1) + (r2 - l2);

        }

        ll bit = now % 2;
        ll i_ans = bit << i;
        ans += i_ans;
    }

    cout << ans << endl;

}