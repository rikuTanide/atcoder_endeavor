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


char solve(int i, vector<vector<int>> &edge, vector<char> &use, set<int> &parents) {
    if (use[i] != '-') return use[i];
    if (parents.find(i) != parents.end()) return use[i] = 'x';

    parents.insert(i);
    for (int j : edge[i]) {
        char now = solve(j, edge, use, parents);
        if (now == 'x') return use[i] = 'x';
    }
    parents.erase(i);
    return use[i] = 'o';
}

int main() {
    int n;
    cin >> n;

    int a;
    cin >> a;
    vector<P> ac(a);
    for (P &p : ac) cin >> p.first >> p.second;
    for (P &p : ac) p.first--, p.second--;

    int b;
    cin >> b;
    vector<P> bc(b);
    for (P &p : bc) cin >> p.first >> p.second;
    for (P &p : bc) p.first--, p.second--;

    int ans = 0;
    rep(i, 1 << b) {

        vector<vector<int>> edges(n);
        vector<char> use(n, '-');
        set<int> parents;

        for (P p : ac) edges[p.first].push_back(p.second);
        rep(j, b) {
            P p = bc[j];
            if ((i >> j) & 1) {
                edges[p.second].push_back(p.first);
            } else {
                use[p.first] = 'x';
            }
        }


        // 塗れる・塗れない・まだわからない
        // 自分のおやがすべて塗れるなら塗れる
        // 自分のおやがxもしくは、自分か親が強連結成分の中身なら塗れない

        rep(j, n) use[j] = solve(j, edges, use, parents);
        int now = count(use.begin(), use.end(), 'o');
        cmax(ans, now);
    }
    cout << ans << endl;
}
