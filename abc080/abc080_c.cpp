#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
//using namespace boost::multiprecision;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
const ll INF = 1e15;
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
const int mod = 1000000007;
//const ll mod = 1e10;
typedef priority_queue<long long, vector<long long>, greater<long long> > PQ_ASK;

int main() {
    int n;
    cin >> n;
    vector<vector<bool>> sell(n, vector<bool>(10));
    rep(i, n) rep(j, 10) {
            int k;
            cin >> k;
            sell[i][j] = k == 1;
        }

    vector<vector<ll>> benefit(n, vector<ll>(11));
    rep(i, n) rep(j, 11) cin >> benefit[i][j];
    ll ans = -INF;
    for (ll i = 1; i < (1 << 10); i++) {
        ll now = 0;
        for (ll k = 0; k < n; k++) {
            ll m = 0;
            for (ll l = 0; l < 10; l++) {
                if ((i >> l) & 1) if (sell[k][l]) m++;
            }
            now += benefit[k][m];
        }
        cmax(ans, now);
    }
    cout << ans << endl;
}