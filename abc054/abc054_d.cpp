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

struct Drag {
    int a, b, c;
};


std::istream &operator>>(std::istream &in, Drag &o) {
    cin >> o.a >> o.b >> o.c;
    return in;
}

vector<Drag> pairing(vector<Drag> &v) {
    int n = v.size();

    map<P, int> m;

    rep(i, 1 << n) {
        vector<Drag> uses;
        rep(j, n) if ((i >> j) & 1) uses.push_back(v[j]);

        Drag d = {0, 0, 0};
        for (Drag u : uses) d.a += u.a, d.b += u.b, d.c += u.c;

        P p(d.a, d.b);
        if (m.find(p) == m.end()) m[p] = d.c;
        else
            cmin(m[p], d.c);

    }

    vector<Drag> ans;
    for (auto &e : m) {
        ans.push_back(Drag{(int) e.first.first, (int) e.first.second, e.second});
    }
    return ans;

}

int main() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;

    vector<Drag> drags(n);
    rep(i, n) cin >> drags[i];

    vector<Drag> drags1, drags2;
    rep(i, n) (i % 2 ? drags1 : drags2).push_back(drags[i]);

    auto p1 = pairing(drags1);
    auto p2 = pairing(drags2);

    ll ans = INF;

    for (Drag d1 : p1) {
        for (Drag d2 : p2) {
            Drag d = {d1.a + d2.a, d1.b + d2.b, d1.c + d2.c};
            if (!(d.a == 0 || d.b == 0)) {
                int g = gcd(d.a, d.b);
                d.a /= g;
                d.b /= g;
            }

            if (d.a == m1 && d.b == m2) {
                cmin(ans, (ll) d.c);
            }
        }
    }

    if (ans == INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}
