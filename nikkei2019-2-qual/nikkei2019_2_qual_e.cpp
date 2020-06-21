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

int main() {
    int n;
    ll k;
    cin >> n >> k;

    if (k > (n + 1) / 2) {
        cout << -1 << endl;
        ret();
    }

    ll a = k;
    ll b = k + 2 * n - 1;
    ll c = b + k;

    set<int> sa, sb, sc;
    vector<vector<ll>> ans;

    while (k + n <= b && k + 2 * n <= c) {
        sa.insert(a);
        sb.insert(b);
        sc.insert(c);
        ans.push_back({a, b, c});
        a++;
        b -= 2;
        c--;
    }

    b = k + 2 * n - 1;
    c = k + 3 * n - 1;

    while (sb.count(b)) b--;
    while (sc.count(c)) c--;
    while (a < k + n && k + n <= b && k + 2 * n <= c) {
        sa.insert(a);
        sb.insert(b);
        sc.insert(c);

        ans.push_back({a, b, c});
        a++;
        b--;
        c--;

        while (sb.count(b)) b--;
        while (sa.count(c)) c--;

    }

    for (vector<ll> &v: ans) printf("%lld %lld %lld\n", v[0], v[1], v[2]);


}


