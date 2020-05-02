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

typedef pair<ll, ll> P;

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;


struct Q {
    ll a, b, c, d;
};

std::istream &operator>>(std::istream &in, Q &o) {
    cin >> o.a >> o.b >> o.c >> o.d;
    o.a--;
    o.b--;
    return in;
}

int check(vector<int> &v, vector<Q> &qs) {
    ll ans = 0;
    for (Q &q : qs) {
        if (v[q.b] - v[q.a] == q.c) ans += q.d;
    }
    return ans;
}

ll rec(vector<int> v, int n, int m, vector<Q> &qs) {
    ll ans = 0;
    if (v.size() == n) {
        ll now = check(v, qs);
        cmax(ans, now);
        return ans;
    }
    int start = v.empty() ? 1 : v.back();
    for (int i = start; i <= m; i++) {
        vector<int> u = v;
        u.push_back(i);
        ll now = rec(u, n, m, qs);
        cmax(ans, now);
    }
    return ans;
}

int main() {

    int n, m, q;
    cin >> n >> m >> q;
    vector<int> v;

    vector<Q> qs(q);
    rep(i, q) cin >> qs[i];

    ll ans = rec(v, n, m, qs);
    cout << ans << endl;

}

