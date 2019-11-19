#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
typedef pair<int, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = 1001001001;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)

const int mod = 1e9 + 7;


int main() {
    int n;
    string s;
    cin >> n >> s;

    auto s2 = s.substr(0, n / 2);

    cout << (s2 + s2 == s ? "Yes" : "No") << endl;

}

