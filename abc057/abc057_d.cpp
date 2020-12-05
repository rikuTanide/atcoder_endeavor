#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<int> &o) {
    int a;
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

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;


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
    map<ll, ll> factors;
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

    for (auto e : factors) {

        for (int k = 0; k < e.second; k++) {
            s *= e.first;
        }
    }

    return s;
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    vector<ll> v(n);
    rep(i, n) cin >> v[i];

    sort(v.rbegin(), v.rend());
    double ave = accumulate(v.begin(), v.begin() + a, 0.0) / a;

    ll mi = v[a - 1];
    ll ma = v.front();

    ll mic = count(v.begin(), v.end(), mi);
    ll mi_c = count(v.begin(), v.begin() + a, mi);
    ll ma_c = count(v.begin(), v.begin() + b, mi);

    if (ma != mi) {

        ll t = comb(mic, mi_c);

        cout << setprecision(20) << ave << endl << t << endl;
        ret();
    }


    ll ans = 0;
    for (int i = mi_c; i <= ma_c; i++) {
        ll now = comb(mic, i);
        ans += now;
    }
    cout << setprecision(20) << ave << endl << ans << endl;


}
