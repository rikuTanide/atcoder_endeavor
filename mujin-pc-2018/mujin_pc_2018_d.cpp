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

int rev(int x) {
    int ans = 0;
    while (x > 0) {
        ans *= 10;
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

P p(int x, int y) {
    return P(min(x, y), max(x, y));
}

bool check(int x, int y, set<P> &memo1, set<P> &memo2) {
    if (x == 0 || y == 0) return true;
    if (memo1.find(p(x, y)) != memo1.end()) return false;
    if (memo2.find(p(x, y)) != memo2.end()) return false;
    memo2.insert(p(x, y));
    if (x < y) {
        x = rev(x);
    } else {
        y = rev(y);
    }
    if (x < y) {
        y = y - x;
    } else {
        x = x - y;
    }
    return check(x, y, memo1, memo2);

}

int main() {

    int n, m;
    cin >> n >> m;
    int ans = 0;
    set<P> memo1;
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            set<P> memo2;
            bool b = check(x, y, memo1, memo2);
            if (!b) {
                ans++;
                for (P p : memo2) memo1.insert(p);
            }
        }
    }
    cout << ans << endl;
}
