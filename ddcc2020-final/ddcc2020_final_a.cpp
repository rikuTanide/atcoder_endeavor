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

int factorize(ll n) {
    int res = 0;

    for (ll i = 2; i * i <= n; i++) {
        if (n % i != 0) {
            continue;
        }
        while (n % i == 0) {
            n /= i;
            res++;
        }
    }

    if (n != 1) res++;
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    rep(i, n)cin >> v[i];
    vector<int> k(n);
    rep(i, n) {
        k[i] = factorize(v[i]);
//        for (int j = 2; j <= v[i]; j++) {
//            if (v[i] % j == 0) k[i]++;
//        }
    }

    int t = 0;
    for (int u : k) t ^= u;

    cout << (t == 0 ? "Yes" : "No") << endl;

}
