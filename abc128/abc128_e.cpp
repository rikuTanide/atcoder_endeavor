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

typedef tuple<string, int, int> T;

int main() {
    ll n, q;
    cin >> n >> q;

    vector<tuple<ll, ll, ll >> xst(n);
    rep(i, n) {
        ll s, t, x;
        cin >> s >> t >> x;

        s = s - x;
        t = t - x;

        auto tp = tuple<ll, ll, ll>(x, s, t);
        xst[i] = tp;
    }
    sort(xst.begin(), xst.end());

    set<P> st;
    rep(i, q) {
        ll x;
        cin >> x;
        st.emplace(x, i);
    }

    vector<ll> ans(q, -1);
    rep(i, n) {
        ll x = get<0>(xst[i]);
        ll s = get<1>(xst[i]);
        ll t = get<2>(xst[i]);

        auto it = st.lower_bound(P(s, 0));
        auto end = st.upper_bound(P(t - 1, q));
        while (it != end) {
            ans[it->second] = x;
            st.erase(it++);
        }
    }

    rep(i, q) {
        cout << ans[i] << endl;
    }

}

