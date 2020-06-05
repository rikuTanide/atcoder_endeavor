#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<int> &o) {
    int a;
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
#define whole(f, x, ...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;


int main() {
    int n;
    cin >> n;

    vector<vector<char>> grid(n, vector<char>(n));
    rep(y, n) rep(x, n) cin >> grid[y][x];

    bool is_all_white = [&] {
        rep(y, n) rep(x, n) if (grid[y][x] == '#') return false;
        return true;
    }();

    if (is_all_white) {
        cout << -1 << endl;
        ret();
    }

    int mi = INT_MAX;
    auto x = [&](int i) {
        int b = 0;
        int w = 0;
        rep(j, n) if (grid[i][j] == '#') b++; else w++;

        bool has_b = [&] {
            rep(j, n) if (grid[j][i] == '#') return true;
            return false;
        }();

        if (has_b) return w;
        return w + 1;
    };
    rep(i, n) cmin(mi, x(i));

    int c = [&] {
        int ans = 0;
        rep(i, n) {
            bool b = [&] {
                rep(j, n) {
                    if (grid[j][i] == '.') return true;
                }
                return false;
            }();
            if (b) ans++;
        }
        return ans;
    }();

    cout << c + mi << endl;
}
