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


int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<bool>> edges(n, vector<bool>(n, false));
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        edges[a][b] = true;
        edges[b][a] = true;
    }

    auto check = [&](vector<int> &as) -> bool {
        int n = as.size();
        rep(i, n) {
            rep(j, n) {
                if (i == j) continue;
                if (!edges[as[i]][as[j]]) return false;
            }
        }
        return true;
    };

    ll ans = INF;
    rep(i, 1 << n) {
        vector<int> as, bs;
        rep(j, n) if ((i >> j) & 1) as.push_back(j); else bs.push_back(j);
        if (check(as) && check(bs)) {
            ll ac = as.size(), bc = bs.size();
            ll now = ac * (ac - 1) / 2 + bc * (bc - 1) / 2;
            cmin(ans, now);
        }
    }

    ans = ans == INF ? -1 : ans;
    cout << ans << endl;

}