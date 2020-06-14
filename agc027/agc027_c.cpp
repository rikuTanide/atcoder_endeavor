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
    int n, m;
    string s;
    cin >> n >> m >> s;

    vector<int> as(n), bs(n);

    vector<set<int>> edges(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].insert(b);
        edges[b].insert(a);
    }

    set<int> q;

    rep(i, n) {
        for (int e: edges[i]) {
            if (s[e] == 'A') as[i]++;
            else bs[i]++;
        }
        if (as[i] == 0 || bs[i] == 0)q.insert(i);
    }

    int lef = n;
    while (q.size()) {
        int x = *q.begin();
        q.erase(q.begin());

        lef--;

        for (int e : edges[x]) {
            if (e == x)continue;
            edges[e].erase(x);
            if (s[x] == 'A') as[e]--;
            else bs[e]--;
            if (as[e] == 0 || bs[e] == 0) q.insert(e);
        }
    }

    string ans = lef == 0 ? "No" : "Yes";
    cout << ans << endl;

}
