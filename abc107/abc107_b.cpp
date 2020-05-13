#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<double, double> P;
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
    int h, w;
    cin >> h >> w;
    vector<vector<char>> v(h, vector<char>(w, ' '));
    rep(y, h) rep(x, w) cin >> v[y][x];

    auto mix_row = [&](int y) {
        set<char> st;
        rep(x, w) st.insert(v[y][x]);
        return st.size() == 2;
    };

    vector<vector<char>> v2;
    rep(y, h) {
        if (!mix_row(y)) continue;
        v2.push_back(v[y]);
    }

    auto mix_col = [&](int x) {
        set<char> st;
        rep(y, h) st.insert(v[y][x]);
        return st.size() == 2;
    };

    vector<vector<char>> v3(v2.size());
    rep(x, w) {
        if (!mix_col(x)) continue;
        rep(y, v2.size()) {
            v3[y].push_back(v2[y][x]);
        }
    }
    if(v3.size() == 0) {
        cout << '#' << endl;
        ret();
    }

    rep(y, v3.size()) {
        rep(x, v3[y].size()) cout << v3[y][x];
        cout << endl;
    }

}
