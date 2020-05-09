#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
typedef pair<ll, ll> P;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
const ll INF = 10e14;
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

ll solve(vector<ll> &numbers, int n, int k, int q, ll target) {
    vector<vector<ll>> tmp(1);
    for (ll l : numbers) {
        if (l < target) tmp.push_back({});
        else tmp.back().push_back(l);
    }
    vector<ll> candidate;
    for (vector<ll> &v : tmp) {
        if (v.size() < k - 1) continue;
        sort(v.begin(), v.end());
        int c = v.size() - k + 1;
        rep(i, c) candidate.push_back(v[i]);
    }
    sort(candidate.begin(), candidate.end());
    if (candidate.size() < q) return INF;
    return candidate[q - 1] - target;
}

int main() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<ll> numbers(n);
    rep(i, n)cin >> numbers[i];
    ll ans = INF;
    rep(i, n) cmin(ans, solve(numbers, n, k, q, numbers[i]));
    cout << ans << endl;
}



