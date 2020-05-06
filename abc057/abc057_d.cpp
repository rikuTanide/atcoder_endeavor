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

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;
typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;
const int mod = 1000000007;

map<ll, int> factorize(ll n) {
    map<ll, int> res;

    for (ll i = 2; i * i <= n; i++) {
        if (n % i != 0) {
            continue;
        }
        res[i] = 0;
        while (n % i == 0) {
            n /= i;
            res[i]++;
        }
    }

    if (n != 1) res[n] = 1;
    return res;
}

ll comb(ll l, ll r) {
    vector<ll> factors(50);
    for (ll j = l; j > (l - r); j--) {
        auto fs = factorize(j);
        for (auto f : fs) {
            factors[f.first] += f.second;
        }
    }

    for (ll j = 1; j <= r; j++) {
        auto fs = factorize(j);
        for (auto f : fs) {
            factors[f.first] -= f.second;
        }
    }

    ll s = 1;

    for (int j = 1; j < 50; j++) {
        for (int k = 0; k < factors[j]; k++) {
            s *= j;
        }
    }

    return s;
}


ll f(ll a, ll b, ll c) {
    ll ans = 0;
    for (ll i = a; i <= b; i++) {
        ll now = comb(c, i);
        ans += now;
    }
    return ans;
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    vector<ll> items(n);
    rep(i, n) cin >> items[i];
    sort(items.rbegin(), items.rend());

    double sum = accumulate(items.begin(), items.begin() + a, 0ll);

    printf("%.20f\n", sum / a);

    int k = items[a - 1];
    int c = count(items.begin(), items.end(), k);

    if (k == items.front()) {
        ll p = f(a, b, c);
        cout << p << endl;
    } else {
        int g = count_if(items.begin(), items.end(), [&](int i) { return i > k; });
        ll p = comb(c, a - g);
        cout << p << endl;
    }
}
