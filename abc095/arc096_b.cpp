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
    ll n, c;
    cin >> n >> c;

    vector<P> counter(n);

    rep(i, n) {
        ll x, v;
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
        ll left_calorie = 0;
        ll left_max = 0;
        ll l_i = 0;
        for (ll i = 0; i < n; i++) {
            left_calorie += getCalorie(i);
            ll now = left_calorie - getLeftDistance(i);
            if (left_max < now) {
                l_i = i;
                left_max = now;
            }
        }

        ll right_calorie = 0;
        ll right_max = 0;
        for (ll i = n - 1; i > l_i; i--) {
            right_calorie += getCalorie(i);
            ll now = right_calorie - (getRightDistance(i) * 2);
            cmax(right_max, now);
        }

        tokei = right_max + left_max;
    }

    ll han_tokei = 0;
    {
        // 反時計回り
        ll right_calorie = 0;
        ll right_max = 0;
        ll r_i = 0;
        for (ll i = n - 1; i >= 0; i--) {
            right_calorie += getCalorie(i);
            ll now = right_calorie - getRightDistance(i);
            if (right_max < now) {
                r_i = i;
                right_max = now;
            }
        }

        ll left_calorie = 0;
        ll left_max = 0;
        for (ll i = 0; i < r_i; i++) {
            left_calorie += getCalorie(i);
            ll now = left_calorie - (getLeftDistance(i) * 2);
            cmax(left_max, now);
        }

        han_tokei = right_max + left_max;
    }

    ll l_r = 0; // 一旦左に行って、折り返して右に行く
    {
        ll left_calorie = 0;
        ll left_max = 0;
        ll l_i = 0;
        for (ll i = 0; i < n; i++) {
            if (getLeftDistance(i) * 2 >= c) break;
            left_calorie += getCalorie(i);
            ll now = left_calorie - getLeftDistance(i) * 2;
            if (left_max < now) {
                l_i = i;
                left_max = now;
            }
        }

        ll right_max = 0;
        ll right_calorie = 0;
        for (ll i = n - 1; i > l_i; i--) {
            right_calorie += getCalorie(i);
            ll now = right_calorie - getRightDistance(i);
            cmax(right_max, now);
        }
        l_r = left_max + right_max;
    }

    ll r_l = 0; // 一旦右に行って、折り返して左に行く
    {
        ll right_calorie = 0;
        ll right_max = 0;
        ll r_i = n;
        for (ll i = n - 1; i >= 0; i--) {
            if (getRightDistance(i) * 2 >= c) break;
            right_calorie += getCalorie(i);
            ll now = right_calorie - getRightDistance(i) * 2;
            if(right_max < now) {
                r_i = i;
                right_max = now;
            }

        }

        ll left_max = 0;
        ll left_calorie = 0;
        for (ll i = 0; i < r_i; i++) {
            left_calorie += getCalorie(i);
            ll now = left_calorie - getLeftDistance(i);
            cmax(left_max, now);
        }
        r_l = left_max + right_max;
    }

    ll ans = 0;
    cmax(ans, tokei);
    cmax(ans, han_tokei);
    cmax(ans, l_r);
    cmax(ans, r_l);

    cout << ans << endl;

}
