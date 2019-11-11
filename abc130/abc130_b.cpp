#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
typedef pair<int, int> P;
//typedef pair<ll, ll> P;
const ll INF = 1001001001;
const int mod = 1000000007;

int main() {
    int n, x;
    cin >> n >> x;
    ll sum = 0;
    ll count = 0;
    rep(i, n) {
        int l;
        cin >> l;
        sum += l;
        count++;
        if (sum > x) {
            cout << count << endl;
            return 0;
        }
    }

}