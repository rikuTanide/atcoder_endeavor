#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const long double EPS = 1e-9;

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

void pop(int n, vector<ll> &tree, vector<int> &parents, int i, ll method) {
    if (i == n || i == -1) return;
    pop(n, tree, parents, parents[i], tree[i]);
    tree[i] = method;
}

ll dfs(int n, int m, vector<ll> tree, vector<int> &parents, vector<ll> &methods, int i) {
    ll ans = accumulate(tree.begin(), tree.end(), 0ll);
    if (i == m) return ans;

    rep(j, n) {
        vector<ll> t = tree;
        pop(n, t, parents, j, methods[i]);
        ll now = dfs(n, m, t, parents, methods, i + 1);
        cmax(ans, now);
    }


    return ans;

}

int main() {

    int n;
    cin >> n;

    vector<ll> tree(n);
    rep(i, n) cin >> tree[i];

    vector<int> parents(n, -1);

    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        parents[b] = a;

    }


    int m;
    cin >> m;

    vector<ll> methods(m);
    rep(i, m) cin >> methods[i];

    sort(methods.rbegin(), methods.rend());

    ll ans = dfs(n, m, tree, parents, methods, 0);
    cout << ans << endl;

}

