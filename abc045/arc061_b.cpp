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


int main() {

    struct Direction {
        int x, y;
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


    ll h, w, n;
    cin >> h >> w >> n;

    ll ma = (h - 2) * (w - 2);
    set<P> points;
    rep(i, n) {
        ll a, b;
        cin >> a >> b;
        points.insert({a, b});
    }

    set<P> need_check;
    for (P p : points) {


        for (Direction &d : directions) {
            P next = {p.first + d.y, p.second + d.x};
            if (next.first <= 1) continue;
            if (next.first >= h) continue;
            if (next.second <= 1) continue;
            if (next.second >= w) continue;
            need_check.insert(next);
        }
    }

    vector<ll> ans(10);

    for (P p : need_check) {
        int count = 0;
        for (Direction &d : directions) {
            P q = {p.first + d.y, p.second + d.x};
            if (points.find(q) != points.end()) count++;
        }
        ans[count]++;
        ma--;
    }

    ans[0] = ma;
    for (ll i : ans) cout << i << endl;

}