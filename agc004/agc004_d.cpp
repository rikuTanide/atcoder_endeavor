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

int rec(int i, int k, vector<int> &parents, vector<int> &depth, vector<bool> &change) {
    if (i == 0) return depth[0] = 0;
    if (depth[i] != -1) return depth[i];

    int prev = parents[i];
    int parent_depth = rec(prev, k, parents, depth, change);
    int current_depth = parent_depth + 1;

    if (current_depth > k) {
        change[i] = true;
        return depth[i] = 1;
    } else {
        return depth[i] = current_depth;
    }

}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> depth(n, -1);
    vector<bool> change(n, false);

    vector<int> parents(n, -1);
    rep(i, n) {
        int a;
        cin >> a;
        a--;
        if (i == 0) {
            if (a != 0) change[0] = true;
            continue;
        }
        parents[i] = a;

    }

    vector<bool> has_child(n, false);
    rep(i, n)if (i != 0) has_child[parents[i]] = true;


    rep(i, n) if (!has_child[i]) depth[i] = rec(i, k, parents, depth, change);

    int ans = count(change.begin(), change.end(), true);

    cout << ans << endl;
}
