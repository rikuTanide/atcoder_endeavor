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
struct Direction {
    int y, x;
};

vector<Direction> directions = {
        {0,  1},
        {1,  1},
        {1,  0},
        {1,  -1},
        {0,  -1},
        {-1, -1},
        {-1, 0},
        {-1, 1},
        {0,  0},
};

int main() {
    ll h, w;
    int n;
    cin >> h >> w >> n;

    vector<P> v(n);
    for (P &p: v) cin >> p.first >> p.second;

    set<P> black;
    for (P p : v) black.insert(p);

    set<P> candidate;

    for (P p : v) {


        for (Direction d : directions) {
            ll y = p.first + d.y;
            ll x = p.second + d.x;

            if (y <= 1 || y >= h) continue;
            if (x <= 1 || x >= w) continue;

            candidate.insert({y, x});
        }

    }


    map<P, int> m;

    for (P p: candidate) {
        int count = 0;
        for (Direction d : directions) {
            ll y = p.first + d.y;
            ll x = p.second + d.x;
            P q(y, x);
            if (black.find(q) != black.end()) count++;
        }
        m[p] = count;
    }

    {
        ll all = (h - 2) * (w - 2);
        all -= candidate.size();
        cout << all << endl;
    }

    for (int i = 1; i <= 9; i++) {
        ll ans = 0;
        for (auto e : m) {
            if (e.second == i) ans++;
        }
        cout << ans << endl;
    }


}
