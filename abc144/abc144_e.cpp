#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


bool check(ll mid, ll k, ll n, vector<ll> costs, vector<ll> difficults) {
    ll some = 0;
    for (ll x = 0; x < n; x++) {
        ll cost = costs.at(x);
        ll difficult = difficults.at(x);
        // この人がmidに収まるには、ドレだけの時間が足りていないか
        // この人がmidに収まるには、何回トレーニングしなければいけないか
        ll t = cost - mid / difficult;
        if (t < 0) {
            continue;
        }
        some += t;
    }
    return some <= k;
}

int main() {
    ll n, k;
    cin >> n;
    cin >> k;

    vector<ll> costs(n);
    vector<ll> difficults(n);

    for (ll x = 0; x < n; x++) {
        cin >> costs.at(x);
    }

    for (ll x = 0; x < n; x++) {
        cin >> difficults.at(x);
    }

    sort(costs.begin(), costs.end());
    sort(difficults.rbegin(), difficults.rend());

    ll cell = 10e12;
    ll floor = -1;
    while (floor + 1 < cell) {
        ll mid = (cell + floor) / 2;
        if (check(mid, k, n, costs, difficults)) {
            cell = mid;
        } else {
            floor = mid;
        }
    }

    cout << cell << endl;

}
