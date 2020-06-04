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

int rec(int i, int k, vector<int> &parents, vector<int> &depth) {
    if (i == 0) return depth[0] = 0;
    if (depth[i] != -1) return depth[i];

    int prev = parents[i];
    if (prev == 0) {
        return depth[i] = 1;
    }

    int parent_depth = rec(prev, k, parents, depth);
    int current_depth = parent_depth + 1;

    if (current_depth > k) {
        depth[prev] = 1;
        parents[prev] = 0;
        return depth[i] = 2;
    } else {
        return depth[i] = current_depth;
    }

}

int main() {

//    ifstream file("C:\\Users\\riku\\Downloads\\1_23.txt");

    int n, k;
    cin >> n >> k;

    assert(n > 1);

    vector<int> depth(n, -1);
    vector<int> parents(n, -1);
    rep(i, n) {
        int a;
        cin >> a;
        a--;
        parents[i] = a;
    }

    vector<int> orig = parents;

    parents[0] = 0;


    rep(i, n) depth[i] = rec(i, k, parents, depth);

    int ans = 0;
    rep(i, n) if (parents[i] != orig[i]) ans++;
    
    cout << ans << endl;
}