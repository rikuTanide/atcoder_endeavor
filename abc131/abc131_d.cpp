#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
const ll INF = 1001001001;

const int mod = 1000000007;

ll gcd(ll x, ll y) {
    if (y == 0) {
        return x;
    }
    return gcd(y, x % y);
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

int main() {
    ll n;
    cin >> n;
    priority_queue<P> ab;

    rep(i, n) {
        ll a, b;
        cin >> a >> b;
        ab.push(P(b, a));
    }

    ll current_limit = INF;
    while (!ab.empty()) {
        P p = ab.top();
        ll this_limit = p.first;
        ll this_time = p.second;

        current_limit = min(current_limit, this_limit);
        current_limit -= this_time;

        if (current_limit < 0) {
            cout << "No" << endl;
            return 0;
        }
        ab.pop();
    }

    cout << "Yes" << endl;
}