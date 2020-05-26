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

typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;

ll check(int n, vector<P> &v, ll target) {
    ll sum = 0;
    rep(i, n) {
        ll from = v[i].first;
        ll diff = target - from;
        if (diff <= 0) continue;
        ll par = v[i].second;
        ll c = (diff + par - 1) / par;
        sum += c;
    }
    return sum;
}

ll solve(int n, vector<P> &v, ll target) {
    ll sum = 0;
    rep(i, n) {
        ll from = v[i].first;
        ll diff = target - from;
        if (diff <= 0) continue;
        ll par = v[i].second;
        ll k = (diff + par - 1) / par;

        ll now = k * (2 * v[i].first + (k - 1) * par) / 2;
        sum += now;

    }
    return sum;
}

int main() {
    int k, n;
    cin >> k >> n;

    vector<P> v(n);
    rep(i, n) cin >> v[i].first >> v[i].second;

    ll target = [&] {
        ll floor = 0, ceil = INF;
        while (true) {
            ll mid = (floor + ceil) / 2;
            ll count = check(n, v, mid);
            if (count == k) return mid;
            if (count < k) floor = mid;
            else ceil = mid;
        }
    }();


    cout << solve(n, v, target) << endl;

}