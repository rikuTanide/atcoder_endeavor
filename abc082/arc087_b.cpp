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
    string s;
    int x, y;
    cin >> s >> x >> y;

    int n = s.size();

    unordered_map<int, unordered_map<int, bool>> prev;
    prev[0][0] = true;

    char o = 'h';
    rep(i, n) {

        auto can = [&](int yi, int xi) -> bool {
            int l = abs(y - yi) + abs(x - xi);
            if (i + l > n) return false;
            return true;
        };

        if (s[i] == 'T') {
            o = (o == 'v' ? 'h' : 'v');
        } else {
            if (o == 'v') {
                unordered_map<int, unordered_map<int, bool>> next;
                for (auto &e : prev) {
                    for (auto &f: e.second) {
                        int py = e.first;
                        int px = f.first;
                        if (can(py + 1, px)) next[py + 1][px] = true;
                        if (can(py - 1, px)) next[py - 1][px] = true;
                    }
                }
                prev = next;
            } else {
                unordered_map<int, unordered_map<int, bool>> next;
                for (auto &e : prev) {
                    for (auto &f: e.second) {
                        int py = e.first;
                        int px = f.first;
                        if (can(py, px + 1)) next[py][px + 1] = true;
                        if (can(py, px - 1)) next[py][px - 1] = true;
                    }
                }
                prev = next;
            }
        }
    }

    bool ok = prev[y][x];
    cout << (ok ? "Yes" : "No") << endl;

}
