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
/*
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

ll f(ll k) {


    auto fs = factorize(k);
    ll sum = 1;
    for (auto e : fs) {
        ll now = e.second + 1;
        sum *= now;
    }
    return sum;
}
*/

//エラトステネスの篩
void Eratosthenes(vector<bool> &arr, int n) {
    for (int i = 2; i < sqrt(n); i++) {
        if (arr[i]) {
            for (int j = 0; i * (j + 2) < n; j++) {
                arr[i * (j + 2)] = false;
            }
        }
    }
}

map<ll, ll> f(ll k, vector<map<ll, ll>> &memo) {
    for (ll i = 2; i * i <= k; i++) {
        if (k % i == 0) {
            ll t = k / i;
            map<ll, ll> m = memo[t];
            m[i]++;
            return m;
        }
    }
    __throw_runtime_error("konaide");
}

int main() {
    ll n;
    cin >> n;

    vector<bool> fac_memo(n + 1, true);
    Eratosthenes(fac_memo, n + 1);

    vector<map<ll, ll>> memo(n + 1);

    for (ll k = 1; k <= n; k++) {
        if (fac_memo[k]) memo[k][k] = 1;
        else memo[k] = f(k, memo);
    }

    ll ans = 0;

    for (ll k = 1; k <= n; k++) {
        ll sum = 1;
        for (auto e : memo[k]) {
            ll p = (e.second + 1);
            sum *= p;
        }
        sum *= k;
        ans += sum;
    }

    cout << ans - 1 << endl;

}
