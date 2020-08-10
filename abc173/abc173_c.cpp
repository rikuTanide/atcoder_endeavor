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

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

int main() {
    int h, w, k;
    cin >> h >> w >> k;

    vector<vector<char>> grid(h, vector<char>(w));
    rep(y, h) rep(x, w) cin >> grid[y][x];
    int ans = 0;
    rep(hi, 1 << w) {
        rep(vi, 1 << h) {

            vector<vector<char>> tmp = grid;

            rep(hj, w) {
                if ((hi >> hj) & 1) {

                    rep(y, h) {
                        tmp[y][hj] = 'r';
                    }

                }
            }

            rep(vj, h) {
                if ((vi >> vj) & 1) {
                    rep(x, w) {
                        tmp[vj][x] = 'r';
                    }
                }
            }

            int c = 0;
            rep(y, h) rep(x, w) {
                    if (tmp[y][x] == '#') c++;
                }
            if (c == k) ans++;


        }
    }

    cout << ans << endl;
}
