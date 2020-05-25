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

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//const ll mod = 1e10;
typedef priority_queue<string, vector<string>, greater<string> > PQ_ASK;


class WarchallFloyd {

    int n;
    vector<vector<ll>> distances;

public:
    WarchallFloyd(int n) : n(n), distances(n, vector<ll>(n, 0)) {
        rep(i, n) distances[i][i] = 1;
    };

    void warshall_floyd() {
        for (int k = 0; k < n; k++) {       // 経由する頂点
            for (int i = 0; i < n; i++) {    // 始点
                for (int j = 0; j < n; j++) {  // 終点
                    if (distances[i][j] == 0 && (distances[i][k] == 0 || distances[k][j] == 0)) {
                        distances[i][j] = 0;
                    } else {
                        distances[i][j] = max(distances[i][j], distances[i][k] * distances[k][j]);
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
//        distances[to][from] = cost;
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

struct Conversion {
    string from;
    ll rate;
    string to;

    friend std::istream &operator>>(std::istream &in, Conversion &o) {
        cin >> o.from >> o.rate >> o.to;
        return in;
    }

};

int main() {
    int n;
    cin >> n;

    vector<Conversion> conversions(n);
    rep(i, n) cin >> conversions[i];

    map<string, int> m;
    map<int, string> r;
    {
        set<string> s;
        for (Conversion conversion : conversions) s.insert(conversion.from), s.insert(conversion.to);
        int i = 0;
        for (string u : s) m[u] = i, r[i] = u, i++;
    }

    int s = m.size();

    WarchallFloyd wf(s);

    for (Conversion &c: conversions) {

        int from = m[c.from];
        int to = m[c.to];

        wf.add(from, to, c.rate);
    }

    wf.warshall_floyd();

    ll ma = 0;
    rep(i, s) rep(j, s) cmax(ma, wf.distance(i, j));

    rep(i, s) rep(j, s) if (wf.distance(i, j) == ma) {
                printf("1%s=%lld%s\n", r[i].c_str(), ma, r[j].c_str());
                ret();

            }


}
