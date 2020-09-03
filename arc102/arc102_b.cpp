#include <bits/stdc++.h>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

std::istream &operator>>(std::istream &in, set<ll> &o) {
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

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//const ll mod = 1e10;
//typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;

struct Edge {
    int to;
    ll cost;
};

void rec(int n, vector<vector<Edge>> &g, int now, ll cost, vector<int> &count) {
    if (n == now) {
        count[cost]++;
        return;
    }

    for (Edge to : g[now]) {
        rec(n, g, to.to, cost + to.cost, count);
    }

}

vector<vector<Edge>> take(ll l) {
    // まず、右向きのグラフ
    // 右向きの量を減らすと左向きが出る
    // 立ってるビットから戻す

    int ma = [&]() -> int {
        rep(i, 30) {
            if ((1 << (i + 1)) > l) return i;
        }
    }();

    vector<vector<Edge>> ans(ma);

    rep(i, ma) {
        ans[i].push_back(Edge{i + 1, 0ll});
        ans[i].push_back(Edge{i + 1, 1ll << i});
    }

    ll f = 0;
    f += (1 << ma);

    ll nokori = l - (1 << ma);

    for (int i = 30; i >= 0; i--) {
        if ((nokori >> i) & 1) {

            ans[i].push_back({ma, f});
            f += (1 << i);

        }
    }
    return ans;

}

int main() {
    int l;// = 101;
    cin >> l;
    auto g = take(l);

    int count = 0;
    rep(i, g.size()) count += g[i].size();

    printf("%d %d\n", int(g.size()) + 1, count);

    rep(i, g.size()) {
        for (Edge edge : g[i]) {
            printf("%d %d %lld\n", i + 1, edge.to + 1, edge.cost);
        }
    }

//    ret();
//    vector<vector<Edge>> g = {
//            {{1, 1},  {1, 0}},
//            {{2, 2},  {2, 0}},
//            {{3, 4},  {3, 0}, {6, 96}},
//            {{4, 8},  {4, 0}},
//            {{5, 16}, {5, 0}},
//            {{6, 32}, {6, 0}, {6, 64}},
//    };

//    vector<int> count(120, 0);
//    rec(6, g, 0, 0, count);
//
//    rep(i, 120) {
//        cout << i << ' ' << count[i] << endl;
//    }

}
/*
    int n = 13;

    int ma = 200;

    vector<vector<Edge>> g = {
            {{1,  1},  {1, 0}, {7, 64}},
            {{2,  2},  {2, 0}},
            {{3,  4},  {3, 0}},
            {{4,  8},  {4, 0}},
            {{5,  16}, {5, 0}},
            {{6,  32}, {6, 0}},
//            {{12, 0}},
            {},

            {{8,  1},  {8, 0}},
            {{9,  2},  {9, 0}},
            {{10, 4},  {10, 0}},
            {{11, 8},  {11, 0}},
            {{12, 16}, {12,0}},
            {{13,0}}
    };

    vector<int> count(ma, 0);
    rec(n, g, 0, 0, count);

    rep(i, ma) {
        cout << i << ' ' << count[i] << endl;
    }
*/
