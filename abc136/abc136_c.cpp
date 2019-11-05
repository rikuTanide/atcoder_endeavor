#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;

const ll INF = 1001001001;
vector<ll> hs;

bool check(int digit) {
    ll pre = hs[0];
    for (ll i = 1; i < digit; i++) {
        if (!(pre == hs[i] || pre == (hs[i] - 1))) {
            return false;
        }
        pre = hs[i];
    }
    return true;
};

bool dfs(ll digit) {
    if (digit == hs.size()) {

        return check(digit);

    }
    if (!check(digit)) {
        return false;
    }
    if (dfs(digit + 1)) {
        return true;
    }
    hs[digit]--;
    if (dfs(digit + 1)) {
        return true;
    }
    hs[digit]++;
    return false;
}

int main() {

    ll n;
    cin >> n;

    rep(i, n) {
        int a;

        cin >> a;
        hs.push_back(a);
    }


    cout << (dfs(0) ? "Yes" : "No") << endl;

}
