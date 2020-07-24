#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
typedef pair <ll, ll> P;
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

typedef priority_queue <ll, vector<ll>, greater<ll>> PQ_ASK;

ll solve(ll a, ll k) {


    a *= 2;
    k *= 2;

    auto check = [&](ll y, ll x) -> bool {
        for (ll ya : {0ll, k}) {
            for (ll xa : {0ll, k}) {
                ll yf = y + ya;
                ll xf = x + xa;

                ll rr = yf * yf + xf * xf;
                if (rr > (a / 2) * (a / 2)) return false;
            }
        }
        return true;
    };


    if ((a / k) % 2 == 0) {

        ll ans = 0;
        for (ll y = 0; y <= (a / 2); y += k) {
            for (ll x = 0; x <= (a / 2); x += k) {
                bool ok = check(y, x);
                if (ok) ans += 4;
            }
        }
        return ans;

    } else {
        ll ans = 0;
        for (ll y = 0 + (k / 2); y <= (a / 2); y += k) {
            for (ll x = 0 + (k / 2); x <= (a / 2); x += k) {
                bool ok = check(y, x);
                if (ok) ans += 4;
            }
        }

        for (ll y = 0 + (k / 2); y <= (a / 2); y += k) {
            bool ok = check(y, -(k / 2));
            if (ok) ans += 4;
        }

        bool ok = check(-(k / 2), -(k / 2));
        if (ok)ans++;
        return ans;
    }
}

int main() {
    int k;
    cin >> k;

    cout << solve(200, k) << ' ' << solve(300, k) << endl;

}
