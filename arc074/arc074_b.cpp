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
//    for (int i = n; i <= 2 * n; i++) {
//        vector<ll> n2, n3;
//
//        rep(j, i) n2.push_back(numbers[j]);
//        for (int j = i; j < 3 * n; j++) n3.push_back(numbers[j]);
//
//        sort(n2.rbegin(), n2.rend());
//        sort(n3.begin(), n3.end());
//
//        ll a = accumulate(n2.begin(), n2.begin() + n, 0ll);
//        ll b = accumulate(n3.begin(), n3.begin() + n, 0ll);
//        cout << a << ' ' << b << endl;
//    }

    auto f = [&](vector<ll> &v) {
        priority_queue<ll> q;
        rep(i, n) q.push(v[i]);
        ll sum = accumulate(v.begin(), v.begin() + n, 0ll);
        vector<ll> res;
        res.push_back(sum);
        rep(i, n) {
            sum += v[n + i];
            q.push(v[n + i]);
            ll t = q.top();
            sum -= t;
            q.pop();
            res.push_back(sum);
        }
        return res;
    };

    vector<ll> n2 = numbers;
    rep(i, n * 3) n2[i] *= -1;
    vector<ll> r1 = f(n2);

    vector<ll> n3 = numbers;
    reverse(n3.begin(), n3.end());
    vector<ll> r2 = f(n3);

    rep(i, n + 1) r1[i] *= -1;
    reverse(r2.begin(), r2.end());

    ll ans = -INF;
    rep(i, n + 1) cmax(ans, r1[i] - r2[i]);
    cout << ans << endl;
}
