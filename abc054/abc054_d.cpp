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

struct Solution {
    int a, b, c;
};


map<P, int> make_p(vector<Solution> &v) {
    map<P, int> ans;
    int n = v.size();
    rep(i, 1 << n) {
        int a = 0, b = 0, c = 0;
        rep(j, n) if ((i >> j) & 1) {
                a += v[j].a;
                b += v[j].b;
                c += v[j].c;
            }
        P p(a, b);
        if (ans.find(p) == ans.end()) {
            ans[p] = c;
        } else {
            cmin(ans[p], c);
        }
    }
    return ans;
}

int main() {
    int n, ma, mb;
    cin >> n >> ma >> mb;
    vector<Solution> v(n);
    for (Solution &s:v)cin >> s.a >> s.b >> s.c;

    vector<Solution> sol1, sol2;
    rep(i, n)if (i % 2 == 0) sol1.push_back(v[i]);
        else sol2.push_back(v[i]);

    auto p1 = make_p(sol1);
    auto p2 = make_p(sol2);

    auto calc = [](ll x, ll y) -> ll {
        if (x <= y) return 1;
        return (x + y - 1) / y;
    };
    int ans = INT_MAX;
    for (auto e1:p1) {
        P xp = e1.first;
        ll ar = calc(xp.first, ma);
        ll br = calc(xp.second, mb);
        for (int r = 1; r <= 200; r++) {

            ll ta = ma * r;
            ll tb = mb * r;

            ll ya = ta - xp.first;
            ll yb = tb - xp.second;

            P y(ya, yb);
            if (p2.find(y) == p2.end()) continue;
            int c = p2[y];
            int now = e1.second + c;
            cmin(ans, now);
        }
    }
    cout << (ans == INT_MAX ? -1 : ans) << endl;
}
