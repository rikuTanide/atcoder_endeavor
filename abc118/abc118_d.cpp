#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<double, double> P;
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

struct Sushi {
    ll t, d;
    bool first;
};


std::istream &operator>>(std::istream &in, Sushi &o) {
    cin >> o.t >> o.d;
    return in;
}

int gp(int i) {
    switch (i) {

        case 1:
            return 2;
        case 2:
            return 5;
        case 3:
            return 5;
        case 4:
            return 4;
        case 5:
            return 5;
        case 6:
            return 6;
        case 7:
            return 3;
        case 8:
            return 7;
        case 9:
            return 6;
    }
    __throw_runtime_error("konai");
}

int main() {
    int n, m;
    cin >> n >> m;

    set<int> can;
    rep(i, m) cin >> can;

    vector<mp::cpp_int> dp(n + 100, -INF);
    dp[0] = 0;

    rep(i, n) {
        mp::cpp_int now = dp[i];

        for (int j : can) {
            int p = gp(j);
            int next_i = i + p;
            mp::cpp_int next_c = now;
            next_c *= 10;
            next_c += j;
            cmax(dp[next_i], next_c);
        }

    }
    cout << dp[n] << endl;

}