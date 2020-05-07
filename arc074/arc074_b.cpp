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

typedef pair<ll, ll> P;


int main() {
    int n;
    cin >> n;

    vector<ll> numbers(3 * n);
    rep(i, 3 * n) cin >> numbers[i];
    ll ans = -INF;
    for (int i = n; i <= 2 * n; i++) {
        vector<ll> n2, n3;

        rep(j, i) n2.push_back(numbers[j]);
        for (int j = i; j < 3 * n; j++) n3.push_back(numbers[j]);

        sort(n2.rbegin(), n2.rend());
        sort(n3.begin(), n3.end());

        ll a = accumulate(n2.begin(), n2.begin() + n, 0ll);
        ll b = accumulate(n3.begin(), n3.begin() + n, 0ll);
        ll now = a - b;
        cmax(ans, now);
    }
    cout << ans << endl;
}
