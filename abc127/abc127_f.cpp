#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = 1001001001;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)

const int mod = 1e9 + 7;

ll al = 0, ar = 0, bl = 0;

void down(priority_queue<ll> &lowers, priority_queue<ll, vector<ll>, greater<ll>> &uppers, ll a);

void up(priority_queue<ll> &lowers, priority_queue<ll, vector<ll>, greater<ll>> &uppers);

void center(priority_queue<ll> &lowers, priority_queue<ll, vector<ll>, greater<ll>> &uppers);

int main() {

    ll qc;
    cin >> qc;

    priority_queue<ll> lowers;
    priority_queue<ll, vector<ll>, greater<ll>> uppers;
    for (ll i = 0; i < qc; i++) {
        ll q;
        cin >> q;

        if (q == 1) {
            ll a, b;
            cin >> a >> b;
            bl += b;

            down(lowers, uppers, a);

            up(lowers, uppers);
            center(lowers, uppers);
        } else {
            ll x = lowers.top();
            ll ans = (x * lowers.size() - al) + (ar - x * uppers.size()) + bl;
            cout << x << ' ' << ans << endl;
        }
    }

}

void center(priority_queue<ll> &lowers, priority_queue<ll, vector<ll>, greater<ll>> &uppers) {
    if (uppers.size() - lowers.size() == 1) {
        ll a1 = uppers.top();
        uppers.pop();
        lowers.push(a1);
        al += a1, ar -= a1;
    }
}

void up(priority_queue<ll> &lowers, priority_queue<ll, vector<ll>, greater<ll>> &uppers) {
    if (lowers.size() - uppers.size() == 2) {
        ll a0 = lowers.top();
        lowers.pop();
        uppers.push(a0);
        ar += a0, al -= a0;
    }
}

void down(priority_queue<ll> &lowers, priority_queue<ll, vector<ll>, greater<ll>> &uppers, ll a) {
    if (!lowers.empty() && a > lowers.top()) {
        uppers.push(a);
        ar += a;
    } else {
        lowers.push(a);
        al += a;
    }
}
