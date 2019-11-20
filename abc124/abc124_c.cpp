#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
typedef pair<int, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX;
//const int INF = INT_MAX  ;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)

const int mod = 1000000007;

//< ave , a(time), b(manzoku) >
typedef tuple<double, int, int> A;

int gcd(ll x, ll y) {
    if (x < y) swap(x, y);
    if (y == 0) {
        return x;
    }
    return gcd(y, x % y);
}

int main() {
    string s;
    cin >> s;

    bool kitai = true; // trueが0
    int count = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != (kitai ? '0' : '1')) {
            count++;
        }
        kitai = !kitai;
    }

    bool kitai2 = false; // trueが0
    int count2 = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != (kitai2 ? '0' : '1')) {
            count2++;
        }
        kitai2 = !kitai2;
    }

    cout << min(count, count2) << endl;

}

