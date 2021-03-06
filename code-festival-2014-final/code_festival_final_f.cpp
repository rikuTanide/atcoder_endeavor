#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const long double EPS = 1e-9;

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

std::istream &operator>>(std::istream &in, set<char> &o) {
    string a;
    in >> a;
    for (char c : a) o.insert(c);
    return in;
}

std::istream &operator>>(std::istream &in, queue<int> &o) {
    ll a;
    in >> a;
    o.push(a);
    return in;
}

bool contain(set<char> &s, char a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;

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


int check(int n, vector<ll> &v) {
    vector<bool> tmp(n, true);

    auto to_id = [&](int i) {
        return (i + n) % n;
    };

    rep(i, n) {
        ll bi = v[i];
        ll g = gcd(v[to_id(i - 1)], v[to_id(i + 1)]);
        if (bi % g == 0) continue;
//        tmp[to_id(i - 1)] = false;
        tmp[to_id(i)] = false;
//        tmp[to_id(i + 1)] = false;
    }

    int ans = 0;
    rep(i, n) {
        bool b2 = tmp[to_id(i - 2)];
        if (b2) continue;
        ans++;
        tmp[to_id(i - 2)] = true;
        tmp[to_id(i - 1)] = true;
        tmp[to_id(i - 0)] = true;
    }
    return ans;

}

int main() {
    int n;
    cin >> n;
    vector<ll> v(n);
    rep(i, n) cin >> v[i];

    int ans = INT_MAX;
    {
        int now = check(n, v);
        cmin(ans, now);
    }

    v.insert(v.begin(), v.back());
    v.pop_back();
    {
        int now = check(n, v);
        cmin(ans, now);
    }

    v.insert(v.begin(), v.back());
    v.pop_back();
    {
        int now = check(n, v);
        cmin(ans, now);
    }

    v.insert(v.begin(), v.back());
    v.pop_back();
    {
        int now = check(n, v);
        cmin(ans, now);
    }

    cout << ans << endl;

}
