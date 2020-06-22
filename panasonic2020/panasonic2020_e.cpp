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

bool match(string &a, string &b, int as, int ae, int bs, int be) {
    assert(ae - as == be - bs);
    int n = ae - as;
    for (int i = 0; i < n; i++) {
        char x = a[i + as];
        char y = b[i + bs];
        if (x == '?' || y == '?' || x == y) continue;
        return false;
    }

    return true;

}

int check(string &a, string &b, string &c) {
    int la = a.size(), lb = b.size(), lc = c.size();

    vector<bool> ab(la + 1), bc(lb + 1), ac(la + 1);

    // ab
    rep(i, la + 1) {
        ab[i] = match(a, b, i, min(la, i + lb), 0, min(lb, la - i));
    }

    // bc
    rep(i, lb + 1) {
        bc[i] = match(b, c, i, min(lb, i + lc), 0, min(lc, lb - i));
    }

    // ac
    rep(i, la + 1) {
        ac[i] = match(a, c, i, min(la, i + lc), 0, min(lc, la - i));
    }

    assert(ab.back());
    assert(bc.back());
    assert(ac.back());

    int ans = INT_MAX;

    rep(i, la + 1) {
        if (!ab[i])continue;

        rep(j, lb + 1) {
            if (!bc[j])continue;
            if (!ac[min(i + j, la)]) continue;
            int at = la;
            int bt = i + lb;
            int ct = i + j + lc;
            int now = max({at, bt, ct});
            cmin(ans, now);
        }

        for (int j = i + lb; j <= la; j++) {
            if (!ac[j]) continue;
            int at = la;
            int ct = j + lc;
            int now = max({at, ct});
            cmin(ans, now);
        }

    }

    return ans;
}

int main() {

//    ifstream cin("C:\\Users\\riku\\Downloads\\056.txt");

    string a, b, c;
    cin >> a >> b >> c;


    int ans = INT_MAX;
    cmin(ans, check(a, b, c));
    cmin(ans, check(a, c, b));
    cmin(ans, check(b, a, c));
    cmin(ans, check(b, c, a));
    cmin(ans, check(c, a, b));
    cmin(ans, check(c, b, a));

    cout << ans << endl;
}
