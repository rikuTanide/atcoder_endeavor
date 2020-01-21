#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = 10e15;
const ll MINF = -10e10;
const int INF = INT_MAX / 100;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("~/Downloads/02.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;

// http://sampleyy.hatenablog.com/entry/2015/03/28/104040
bool intersection(int ax, int ay, int bx, int by, int cx, int cy, int dx, int dy) {
    int ta = (cx - dx) * (ay - cy) + (cy - dy) * (cx - ax);
    int tb = (cx - dx) * (by - cy) + (cy - dy) * (cx - bx);
    int tc = (ax - bx) * (cy - ay) + (ay - by) * (ax - cx);
    int td = (ax - bx) * (dy - ay) + (ay - by) * (ax - dx);
    return tc * td < 0 && ta * tb < 0;
}

struct Edge {
    int ax, ay, bx, by;
};

int main() {
    int ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;

    int n;
    cin >> n;

    int sx, sy;
    cin >> sx >> sy;

    vector<Edge> edges;

    int px = sx, py = sy;
    rep(i, n - 1) {
        int x, y;
        cin >> x >> y;

        Edge edge = {px, py, x, y};
        edges.push_back(edge);
        px = x;
        py = y;
    }
    {
        Edge edge = {px, py, sx, sy};
        edges.push_back(edge);
    }

    int inter = 0;
    for (Edge edge : edges) {
        if (intersection(ax, ay, bx, by, edge.ax, edge.ay, edge.bx, edge.by)) {
            inter++;
        }
    }

    cout << (inter / 2) + 1 << endl;


}