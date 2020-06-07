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
    int h, w, n;
    cin >> h >> w >> n;

    auto cid = [&](int y, int x) {
        if (x == 0) return y;
        if (y == h) return h + x;
        if (x == w) return h + w + (h - y);
        if (y == 0) return h + w + h + (w - x);
        return -1;
    };

    vector<P> v;
    rep(i, n) {
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        int i1 = cid(y1, x1);
        int i2 = cid(y2, x2);
        if (i1 == -1 || i2 == -1) continue;
        v.emplace_back(i1, i);
        v.emplace_back(i2, i);
    }

    sort(v.begin(), v.end());

    stack<int> s;
    for (P p : v) {
        if (!s.empty() && s.top() == p.second) s.pop();
        else s.push(p.second);
    }

    cout << (s.empty() ? "YES" : "NO") << endl;

}
