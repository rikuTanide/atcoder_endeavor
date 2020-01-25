#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
//typedef pair<ll, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX / 100;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;

P fulfill(ll left, ll right, ll start, ll need) {
    if (right - left + 1 < need) {
        return P(INF, INF);
    }

    if (right < start) {
        return P(right - need + 1, right);
    } else if (left > start) {
        return P(left, left + need - 1);
    } else {

        ll m = need / 2;
        P p(start - m, start + m);
        if (need % 2 == 0) {
            p.first++;
        }
        if (p.first < left) {
            ll zurasu = (left - p.first);
            p.second += zurasu;
            p.first += zurasu;
        } else if (right < p.second) {
            ll zurasu = p.second - right;
            p.first -= zurasu;
            p.second -= zurasu;
        }
        return p;
    }
}

ll count(ll left, ll right) {
    if (right < 0) {
        return count(abs(right), abs(left));
    } else if (0 < left) {
        ll outer = right * (right + 1) / 2;
        ll inner = (left - 1) * left / 2;
        return outer - inner;
    } else {
        ll l = abs(left) * (abs(left) + 1) / 2;
        ll r = right * (right + 1) / 2;
        return l + r;
    }
}

ll check(ll r, ll g, ll b, ll i, ll j) {
    P r_f = fulfill(-INF, i, -100, r);
    P g_f = fulfill(i + 1, j - 1, 0, g);
    P b_f = fulfill(j, INF, 100, b);

    if (r_f.first == INF || g_f.first == INF || b_f.first == INF) {
        return INF;
    }

    ll x = count(r_f.first + 100, r_f.second + 100);
    ll y = count(g_f.first, g_f.second);
    ll z = count(b_f.first - 100, b_f.second - 100);
    return x + y + z;
}

int main() {
    ll r, g, b;
    cin >> r >> g >> b;
    ll ans = INF;
    for (int i = -1000; i < 1000; i++) {
        for (int j = i + 1; j < 1000; j++) {
            ll c = check(r, g, b, i, j);
            cmin(ans, c);
        }
    }
    cout << ans << endl;
}
