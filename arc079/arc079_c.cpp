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


vector<ll> about(vector<ll> numbers, ll n, ll first_count) {
    rep(i, n) numbers[i] += first_count;
    ll n1 = n + 1;
    sort(numbers.begin(), numbers.end());
    rep(i, n) {
        ll a = numbers.front();
        ll b = numbers[i];
        ll diff = b - a;
        ll c = diff / n1;
        ll k = c * n1;
        numbers[i] -= k;
        first_count -= c;
    }
    sort(numbers.begin(), numbers.end());
    ll f = first_count / n;

    rep(i, n) {
        numbers[i] -= (n1 * f);
    }

    ll g = f * n;
    first_count -= g;

    reverse(numbers.begin(), numbers.end());

    rep(i, first_count) {
        numbers[i] -= n1;
    }

    return numbers;
}

ll simulate(vector<ll> numbers, ll n) {
    int count = 0;
    while ((*max_element(numbers.begin(), numbers.end())) >= n) {
        count++;
        rep(i, n) numbers[i]++;
        *max_element(numbers.begin(), numbers.end()) -= (n + 1);
    }
    return count;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> numbers(n);
    rep(i, n) cin >> numbers[i];

    ll ini_target = n * (n - 1);
    ll ini_max = accumulate(numbers.begin(), numbers.end(), 0ll);
    ll first_count = ini_max - ini_target;
    if (first_count <= 0) {
        ll ans = simulate(numbers, n);
        cout << ans << endl;
        ret();

    }
    vector<ll> numbers2 = about(numbers, n, first_count);
    ll si = simulate(numbers2, n);
    ll ans = si + first_count;
    cout << ans << endl;

}
