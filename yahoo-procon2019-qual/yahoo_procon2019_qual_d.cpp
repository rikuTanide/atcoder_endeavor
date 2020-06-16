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

ll cost(int i, int s, vector<ll> &A) {
    if (s == 0) return A[i];
    else if (s == 4) return A[i];
    else if (s == 1 || s == 3) {
        if (A[i] % 2 == 0 && A[i] > 0) return 0;
        else if (A[i] > 0) return 1;
        else return 2;
    } else {
        if (A[i] % 2 == 0) return 1;
        else return 0;
    }
}


int main() {
    int l;
    cin >> l;

    vector<ll> a(l);
    rep(i, l) cin >> a[i];
    vector<vector<ll>> dp(l + 1, vector<ll>(5, INF));
    dp[0][0] = 0;

    rep(i, l) {
        rep(j, 5) {
            for (int k = j; k < 5; k++) {
                cmin(dp[i + 1][k], dp[i][j] + cost(i, k, a));
            }
        }
    }

    ll ans = *min_element(dp[l].begin(), dp[l].end());
    cout << ans << endl;
}
