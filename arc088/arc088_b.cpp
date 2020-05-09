#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<string> &o) {
    string a;
    in >> a;
    o.insert(a);
    return in;
}

std::istream &operator>>(std::istream &in, queue<int> &o) {
    ll a;
    in >> a;
    o.push(a);
    return in;
}

int main() {
    string s;
    cin >> s;
    int n = s.size();

    if (*min_element(s.begin(), s.end()) == *max_element(s.begin(), s.end())) {
        cout << n << endl;
        ret();
    }


    int ans = INT_MAX;
    rep(i, n - 1) {
        if (s[i] == s[i + 1]) continue;
        int k = max(i + 1, n - i - 1);
        cmin(ans, k);
    }
    cout << ans << endl;

}

