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
    cin >> n;

    vector<set<int>> edges(n);
    rep(_, n - 1) {
        int x, y;
        cin >> x >> y;

        x--;
        y--;
        edges[x].insert(y);
        edges[y].insert(x);
    }

    set<P> s;
    rep(i, n) s.insert(P(edges[i].size(), i));
    bool b = [&]() -> bool {
        while (s.size()) {
            if (s.begin()->first == 0) {
                return true;
            }
            int x = s.begin()->second;
            int y = *edges[x].begin();

            for (int r : edges[y]) {
                s.erase(P(edges[r].size(), r));
                edges[r].erase(y);
                s.insert(P(edges[r].size(), r));
            }
            s.erase(P(edges[y].size(), y));
            s.erase(P(edges[x].size(), x));
        }
        return false;
    }();

    cout << (b ? "First" : "Second") << endl;

}
