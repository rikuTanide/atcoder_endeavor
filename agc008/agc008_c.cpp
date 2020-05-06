#include <bits/stdc++.h>


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

std::istream &operator>>(std::istream &in, set<string> &o) {
    string a;
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

typedef pair<ll, double> P;

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

// https://ykmaku.hatenablog.com/entry/2019/02/19/171008
int main() {
    ll i, o, t, j, l, s, z;
    cin >> i >> o >> t >> j >> l >> s >> z;

    ll use_ijl = [&] {
        ll ijl = min({i, j, l});
        if (ijl == 0) return 0ll;
        ll now = 6 + ((i - 1) / 2) * 4 + ((j - 1) / 2) * 4 + ((l - 1) / 2) * 4;
        return now + (o * 2);
    }();

    ll only_ijl = [&] {
        ll now = (i / 2) * 4 + (j / 2) * 4 + (l / 2) * 4;
        return now + (o * 2);
    }();

    ll ans = max(use_ijl, only_ijl);

    cout << ans / 2 << endl;

}
