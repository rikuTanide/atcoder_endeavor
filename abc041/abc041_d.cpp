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


int N, M;

ll dp[1 << 16];
bool bad[16][16];
//-----------------------------------------------------------------
int main() {
    scanf("%d %d", &N, &M);

    rep(i,  M) {
            int x, y;
            scanf("%d %d", &x, &y);
            x--; y--;
            bad[y][x] = true;
    }

    dp[0] = 1;
    rep(i,  1 << N) {
            rep(j,  N) if (!(i & (1 << j))) {
                bool ok = true;
                rep(k,  N) if (i & (1 << k)) if (bad[k][j]) ok = false;
                if (ok) dp[i + (1 << j)] += dp[i];
            }
    }
    cout << dp[(1 << N) - 1] << endl;
}