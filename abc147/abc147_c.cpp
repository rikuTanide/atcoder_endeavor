#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
//typedef long long ll;
typedef long long ll;
//typedef pair<int, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = 10e15;
const ll MINF = -10e10;
//const int INF = INT_MAX / 100;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("~/Downloads/02.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;
const int mod = 1000000007;
const double PI = 3.14159265358979323846;

typedef pair<ll, ll> P;

struct Witness {
    int to;
    bool is_honest;
};

int check(int i, int n, vector<vector<Witness>> &witness) {
    for (int j = 0; j < n; j++) {
        if (((i >> j) & 1) == 0) {
            continue;
        }
        for (Witness &w : witness[j]) {
            bool h = (i >> w.to) & 1;
            if (h != w.is_honest) return -1;
        }
    }
    return __builtin_popcount(i);
}

int main() {

    int n;
    cin >> n;

    vector<vector<Witness>> witness(n);

    rep(i, n) {
        int a;
        cin >> a;
        rep(j, a) {
            int x, y;
            cin >> x >> y;
            x--;
            Witness w{x, y == 1};
            witness[i].push_back(w);
        }
    }

    int ans = 0;
    for (int i = 0; i < (1 << n); i++) {
        int now = check(i, n, witness);
        cmax(ans, now);
    }
    cout << ans << endl;

}