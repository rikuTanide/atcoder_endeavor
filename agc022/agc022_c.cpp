#include <bits/stdc++.h>

const double PI = 3.14159265358979323846;
using namespace std;
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

bool contain(set<char> &s, char a) { return s.find(a) != s.end(); }

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//const ll mod = 1e10;
typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;

class WarchallFloyd {

    int n;
    vector<vector<ll>> distances;

public:
    WarchallFloyd(int n) : n(n), distances(n, vector<ll>(n, INF)) {
        rep(i, n) distances[i][i] = 0;
    };

    void warshall_floyd() {
        for (int k = 0; k < n; k++) {       // 経由する頂点
            for (int i = 0; i < n; i++) {    // 始点
                for (int j = 0; j < n; j++) {  // 終点
                    if (distances[i][j] == INF && (distances[i][k] == INF || distances[k][j] == INF)) {
                        distances[i][j] = INF;
                    } else {
                        distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j]);
                    }
                }
            }
        }
    }

    ll distance(int from, int to) {
        return distances[from][to];
    }

    void add(int from, int to, ll cost) {
        distances[from][to] = cost;
    }


    friend std::istream &operator>>(std::istream &in, WarchallFloyd &o) {
        int from, to;
        ll c;
        cin >> from >> to >> c;
        from--;
        to--;

        o.distances[from][to] = c;
        o.distances[to][from] = c;
        return in;
    }


};

bool check(vector<int> &as, vector<int> &bs, int ignore) {
    WarchallFloyd wf(51);

    for (int k = 1; k <= 50; k++) {
        if (k == ignore) continue;
        for (int n = 0; n <= 50; n++) {
            wf.add(n, n % k, 1);
        }
    }
    wf.warshall_floyd();

    rep(i, as.size()) {
        int a = as[i];
        int b = bs[i];
        if (wf.distance(a, b) >= INF) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int> as(n), bs(n);
    rep(i, n) cin >> as[i];
    rep(i, n) cin >> bs[i];

    if (as == bs) {
        cout << 0 << endl;
        ret();
    }

    if (count(bs.begin(), bs.end(), 0) == n) {
        cout << 2 << endl;
        ret();
    }

    {
        bool b = check(as, bs, -1);
        if (!b) {
            cout << -1 << endl;
            ret();
        }
    }

    ll ans = 0;
    for (int l = 50; l >= 0; l--) {
        bool b = check(as, bs, l);
        if (!b) ans |= (1ll << l);
    }
    cout << (ans ? ans : -1) << endl;

}