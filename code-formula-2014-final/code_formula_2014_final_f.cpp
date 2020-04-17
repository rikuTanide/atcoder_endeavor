#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

std::istream &operator>>(std::istream &in, set<int> &o) {
    ll a;
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


const int mod = 1000000007;

int main() {
    struct Point {
        int size;
        int x, y;
    };
    vector<Point> vs(100);
    for (int k = 100; k > 0; k--) vs[100 - k].size = k * 2;

    vector<vector<Point>> box = {};

    int w = 1500;
    int h = 0;

    for (Point &p : vs) {
        if (w + p.size > 1500) {
            box.push_back({});
            w = 0;
            h += p.size;
        }
        p.x = w + (p.size / 2);
        p.y = h - (p.size / 2);
        w += p.size;
        box.back().push_back(p);
    }

    reverse(vs.begin(), vs.end());
    for (Point &p : vs) {
        cout << p.x << ' ' << p.y << endl;
    }


}

