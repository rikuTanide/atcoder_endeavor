#include <bits/stdc++.h>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

std::istream &operator>>(std::istream &in, set<int> &o) {
    ll a;
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

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
const int mod = 1000000007;
//const ll mod = 1e10;
typedef priority_queue<string, vector<string>, greater<string> > PQ_ASK;

ll gcd(ll x, ll y) {
    if (x > y) swap(x, y);
    ll m = 1;
    while (m != 0) {
        m = y % x;
        y = x;
        x = m;
    }
    return y;
}

int main() {
    ll x, y;
    scanf("%lld/%lld", &x, &y);

    if (x < y) {
        cout << "Impossible" << endl;
        ret();
    }

    {
        ll g = gcd(x, y);
        x /= g;
        y /= g;
    }

    ll c = 2.0 * x / y;

    auto to_m = [&](ll n) -> ll {
        return n * (n + 1) / 2 - n * x / y;
    };

    auto cal_l = [&](ll n, ll m) -> ll {
        return (n * (n + 1) / 2 - m) * y;
    };

    auto cal_r = [&](ll n, ll m) -> ll {
        return x * n;
    };

    vector<P> ans;

    for (ll n = c - 3; n <= c + 3; n++) {
        if (n < 1) continue;
        ll m = to_m(n);
        if (n < m) continue;
        if (m < 1) continue;
        if (n % y != 0) continue;

        ll l = cal_l(n, m);
        ll r = cal_r(n, m);

        if (l == r) {
            ans.emplace_back(n, m);
        }

    }

    if (ans.empty()) {
        cout << "Impossible" << endl;
    } else {
        for (P p : ans) printf("%lld %lld\n", p.first, p.second);
    }


}
