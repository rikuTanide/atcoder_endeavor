#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<double, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

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

struct Participant {
    double x, y, throw_limit, catch_limit;
};

std::istream &operator>>(std::istream &in, Participant &o) {
    cin >> o.x >> o.y >> o.throw_limit >> o.catch_limit;
    return in;
}

int main() {
    int n, m, y, z;
    cin >> n >> m >> y >> z;
    vector<ll> color_points(26);
    vector<ll> color_bit(26);
    vector<ll> color_index(26);
    rep(i, m) {
        char c;
        ll point;
        cin >> c >> point;
        color_points[c - 'A'] = point;
        color_bit[c - 'A'] = i;
        color_index[c - 'A'] = i + 1;
    }

    string s;
    cin >> s;

    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(1 << m, vector<ll>(m + 1, -INF)));
    dp[0][0][0] = 0;

    rep(i, n) {
        char c = s[i];
        int ci = c - 'A';
        ll point = color_points[ci];
        ll bit = 1 << color_bit[ci];
        int cii = color_index[ci];
        rep(j, 1 << m) {
            rep(k, m + 1) {
                if (dp[i][j][k] == -INF) continue;
                ll next_color_set = j | bit;
                ll next_point = point;
                if (k == cii) next_point += y;
                ll prev = dp[i][j][k];
                cmax(dp[i + 1][next_color_set][cii], prev + next_point);
                cmax(dp[i + 1][j][k], prev);
            }
        }
    }
    ll ans = -INF;
    rep(j, 1 << m) {
        ll perfect = j == ((1 << m)-1) ? z : 0;
        rep(k, m + 1) {
            cmax(ans, dp.back()[j][k] + perfect);
        }
    }
    cout << ans << endl;
}

