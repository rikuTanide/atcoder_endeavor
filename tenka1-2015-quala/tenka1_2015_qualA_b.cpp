#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const long double EPS = 1e-9;

//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep(i, n) for (ll i = 0; i < (n); ++i)
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


int main() {
    int n;
    cin >> n;

    ll l = 0, r = 24ll * 60 * 60 * 1000;

    vector<vector<ll>> t(n, vector<ll>(2));

    rep(i, n) {

        rep(j, 2) {
            vector<int> s(4);
            scanf("%d:%d:%d.%d", &s[0], &s[1], &s[2], &s[3]);
            t[i][j] = s[0] * 60 * 60 * 1000 + s[1] * 60 * 1000 + s[2] * 1000 + s[3];
        }
        if (t[i][0] >= t[i][1]) {
            l = max(l, t[i][0] - 1000);
            r = min(r, t[i][1] + 1000);
        }

    }

    rep(x, n) {
        ll tt = t[x][1] - t[x][0];
        if (tt <= 0 || (t[x][0] <= l && r <= t[x][1])) {
            cout << tt + 1000 << endl;
        } else if (r <= t[x][0] || t[x][1] <= l) {
            cout << tt << endl;
        } else {
            cout << -1 << endl;
        }
    }

}
