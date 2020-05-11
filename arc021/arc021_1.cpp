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

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

int main() {
    int n = 4;
    vector<vector<int>> v(n, vector<int>(n));
    rep(y, n) rep(x, n) cin >> v[y][x];

    rep(y, n) rep(x, n) {


            struct Direction {
                int x, y;
            };

            vector<Direction> directions = {
                    {0,  1},
                    {1,  0},
                    {0,  -1},
                    {-1, 0},
            };

            auto reachable = [&](int y, int x) {
                if (x == -1 || x == 4 || y == -1 || y == 4) return false;
                return true;
            };

            for (Direction d : directions) {
                int ny = y + d.y, nx = x + d.x;
                if (!reachable(ny, nx)) continue;
                if (v[y][x] == v[ny][nx]) {
                    cout << "CONTINUE" << endl;
                    ret();
                }
            }

        }
    cout << "GAMEOVER" << endl;
}