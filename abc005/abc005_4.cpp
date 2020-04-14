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

class MatrixSum {
    vector<vector<ll>> sum;
public:
    MatrixSum(ll x, ll y) {
        sum = vector<vector<ll>>(x, vector<ll>(y));
    }

    void add(ll x, ll y) {
        sum[x][y]++;
    }

    void add(ll x, ll y, ll value) {
        sum[x][y] = value;
    }

    ll get(ll x, ll y) {
        if (x == -1 || y == -1) {
            return 0;
        }
        if (x == sum.size() || y == sum[x].size()) {
            return 0;
        }
        return sum[x][y];
    }

    void setUp() {
        for (ll x = 0; x < sum.size(); x++) {
            for (ll y = 0; y < sum[x].size(); y++) {
                sum[x][y] += get(x - 1, y) + get(x, y - 1) - get(x - 1, y - 1);
            }
        }
    }

    ll getSum(ll xs, ll ys, ll xe, ll ye) {
        return get(xe, ye) - get(xs - 1, ye) - get(xe, ys - 1) + get(xs - 1, ys - 1);
    }

};

int main() {
    int n;
    cin >> n;
    vector<vector<ll>> plate(n, vector<ll>(n));
    rep(y, n) rep(x, n) cin >> plate[y][x];

    MatrixSum ms(n, n);
    rep(y, n) rep(x, n) ms.add(x, y, plate[y][x]);
    ms.setUp();

    vector<ll> dp(n * n + 1, 0);

    for (int ys = 0; ys < n; ys++) {
        for (int ye = ys; ye < n; ye++) {
            for (int xs = 0; xs < n; xs++) {
                for (int xe = xs; xe < n; xe++) {
                    int w = xe - xs + 1;
                    int h = ye - ys + 1;
                    int area = w * h;
                    ll sum = ms.getSum(xs, ys, xe, ye);
                    cmax(dp[area], sum);
                }
            }
        }
    }

    rep(i, n * n) {
        cmax(dp[i + 1], dp[i]);
    }

    int q;
    cin >> q;

    rep(i, q) {
        int a;
        cin >> a;
        cout << dp[a] << endl;
    }
}

