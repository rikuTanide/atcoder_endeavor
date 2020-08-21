#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

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

vector<vector<long double>> P;

long double e(int n) {
    long double m = 0;
    for (int i = 1; i <= n - 1; i++) {
        long double now = P[n][i] * (e(i) + 1);
        m += now;
    }

    long double ans = (P[n][n] + m) / (1 - P[n][n]);
    return ans;
}

vector<long double> facts(pow(10, 7));

long double combf(ll l, ll r) {
    long double la = facts[l];
    long double lr = facts[l - r];
    long double d = facts[r];

    long double now = la - lr - d;
    return powl(10, now);
}

int next(int g, int c, int p) {
    vector<int> v;
    if (g != 0) v.push_back(g);
    if (c != 0) v.push_back(c);
    if (p != 0) v.push_back(p);
    sort(v.begin(), v.end());

    if (v.size() == 1) {
        return v[0];
    }

    if (v.size() == 2) {
        return v[0];
    }

    if (v[0] == v[1] && v[1] == v[2]) {
        return g + c + p;
    }

    return v[0];
}


void update(int n) {
    for (int g = 0; g <= n; g++) {
        for (int c = 0; c + g <= n; c++) {
            int p = n - g - c;
            long double now = combf(n, g) * combf(n - g, c) / powl(3, n);
            int ne = next(g, c, p);
            P[n][ne] += now;
        }
    }
}

int main() {
    int n;
    cin >> n;

    facts[0] = 0;
    facts[1] = 0;
    rep(i, pow(10, 4) - 1) {
        if (i <= 1) continue;
        facts[i] = facts[i - 1] + log10l(i);
    }

    P.resize(110, vector<long double>(110, 0));
    rep(i, 105)if (i >= 2) update(i);

    long double ans = e(n);
    cout << setprecision(20) << ans << endl;

}
