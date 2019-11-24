#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
typedef pair<int, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = 10e10;
const ll MINF = -10e10;
//const int INF = INT_MAX;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)

const int mod = 1000000007;

vector<int> seg = {
        0,
        2,
        5,
        5,
        4,
        5,
        6,
        3,
        7,
        6};
int n, m;
vector<int> options;


int minSeg() {

    int ans = 10;
    for (int option : options) {
        ans = min(ans, seg[option]);
    }
    return ans;

}


int maxLen() {


    return n / minSeg();

}


int f(string s) {
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        ans += seg[s[i]];
    }
    return ans;
}

string fMax(string s, string t) {
    if (s == "-1") {
        return t;
    }
    if (t == "-1") {
        return s;
    }
    if (s.length() > t.length()) {
        return s;
    } else if (s.length() < t.length()) {
        return t;
    } else {
        if (s.compare(t) > 0) {
            return s;
        } else {
            return t;
        }
    }
}

int main() {

    cin >> n >> m;
    rep(i, m) {
        int a;
        cin >> a;
        options.push_back(a);
    }
    sort(options.rbegin(), options.rend());

    vector<string> dp(n + 1, "-1");
    for (int i = 0; i <= n; i++) {
        for (int option : options) {
            if (i < seg[option]) {
                continue;
            }
            if (i == seg[option]) {
                char c = '0' + option;
                string s = "";
                s += c;
                dp[i] = fMax(s, dp[i]);
                continue;
            }
            if (dp[i - seg[option]] == "-1") {
                continue;
            }
            dp[i] = fMax(dp[i], dp[i - seg[option]] + (char) ('0' + option));

        }
    }
    cout << dp[n] << endl;
}

