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
const ll INF = 10e15;
const ll MINF = -10e10;
//const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);



int main() {
//    ifstream myfile("C:\\Users\\riku\\Downloads\\b24");

    ll n, c;
    cin >> n >> c;
//    myfile >> n >> c;

    vector<P> counter(n);

    rep(i, n) {
        ll x, v;
//        myfile >> x >> v;
        cin >> x >> v;
        P p(x, v);
        counter[i] = p;
    }


    auto getCalorie = [&](int i) {
        return counter[i].second;
    };

    auto getLeftDistance = [&](int i) {
        return counter[i].first;
    };

    auto getRightDistance = [&](int i) {
        return c - counter[i].first;
    };


    // 時計回り
    ll tokei = 0;
    {
        vector<ll> tokei_ruiseki(n, 0);
        vector<ll> han_tokei_ruiseki(n + 1, 0);

        ll left_calorie = 0;
        ll left_max = 0;
        for (ll i = 0; i < n; i++) {
            left_calorie += getCalorie(i);
            ll now = left_calorie - getLeftDistance(i);
            cmax(left_max, now);
            tokei_ruiseki[i] = left_max;
        }

        ll right_calorie = 0;
        ll right_max = 0;
        for (ll i = n - 1; i > 0; i--) {
            right_calorie += getCalorie(i);
            ll now = right_calorie - (getRightDistance(i) * 2);
            cmax(right_max, now);
            han_tokei_ruiseki[i] = right_max;
        }

        ll ans = 0;
        for (ll l = 0; l < n; l++) {
            ll r = l + 1;
            ll l_max = tokei_ruiseki[l];
            ll r_max = han_tokei_ruiseki[r];
            ll now = l_max + r_max;
            cmax(ans, now);
        }
        tokei = ans;
    }

    ll han_tokei = 0;
    {

        // 反時計回り
        vector<ll> tokei_ruiseki(n + 1, 0);
        vector<ll> han_tokei_ruiseki(n, 0);

        ll right_calorie = 0;
        ll right_max = 0;
        for (ll i = n - 1; i >= 0; i--) {
            right_calorie += getCalorie(i);
            ll now = right_calorie - getRightDistance(i);
            cmax(right_max, now);
            han_tokei_ruiseki[i] = right_max;
        }

        ll left_calorie = 0;
        ll left_max = 0;
        for (ll i = 0; i < n; i++) {
            left_calorie += getCalorie(i);
            ll now = left_calorie - (getLeftDistance(i) * 2);
            cmax(left_max, now);
            tokei_ruiseki[i + 1] = left_max;
        }

        ll ans = 0;
        for (ll r = n - 1; r >= 0; r--) {
            ll l = r;
            ll r_max = han_tokei_ruiseki[r];
            ll l_max = tokei_ruiseki[l];
            ll now = l_max + r_max;
            cmax(ans, now);
        }
        han_tokei = ans;
    }


    ll ans = 0;
    cmax(ans, tokei);
    cmax(ans, han_tokei);

    cout << ans << endl;

}
