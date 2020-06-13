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
typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;

void dfs(int v, int p, int d, vector<ll> &dep, vector<vector<int>> &g) {
    dep[v] = d;
    for (int nv: g[v]) {
        if (nv == p) continue;
        dfs(nv, v, d + 1, dep, g);
    }
}

template<class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

template<class T>
inline bool chmin(T &a, T b) {
    if (a >= b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> g(n);
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }


    ll cmi = INF, lmi = INF;
    rep(i, n) {
        vector<ll> d(n, INF);
        dfs(i, -1, 0, d, g);
        ll ma = 0;
        rep(j, n) {
            chmax(ma, d[j]);
        }
        ll cm = cmi;
        if (chmin(cmi, ma + 1)) {
            vector<ll> cnt(cmi + 1, 0);
            cnt[0] = (int) g[i].size();
            rep(j, n) {
                if (j == i) continue;
                chmax(cnt[d[j]], (ll) g[j].size() - 1);
            }
            ll res = 1;
            for (int j = 0; j < ma; ++j) {
                res *= cnt[j];
            }
            if (cm == ma + 1) chmin(lmi, res);
            else lmi = res;
        }
    }


    rep(i, n) {
        for (int j: g[i]) {
            vector<ll> d(n, INF);
            dfs(i, j, 0, d, g);
            dfs(j, i, 0, d, g);
            ll ma = 0;
            rep(k, n) {
                chmax(ma, d[k]);
            }
            int cm = cmi;
            if (chmin(cmi, ma + 1)) {
                vector<ll> cnt(cmi + 1, 0);
                cnt[0] = max((int) g[i].size() - 1, (int) g[j].size() - 1);
                rep(k, n) {
                    if (k == i || k == j) continue;
                    chmax(cnt[d[k]], (ll) g[k].size() - 1);
                }
                ll res = 2;
                for (int k = 0; k < ma; ++k) {
                    res *= cnt[k];
                }
                if (cm == ma + 1) chmin(lmi, res);
                else lmi = res;
            }
        }
    }

    cout << cmi << " " << lmi << endl;

}