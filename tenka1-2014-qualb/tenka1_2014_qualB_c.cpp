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

std::istream &operator>>(std::istream &in, set<char> &o) {
    string a;
    in >> a;
    for (char c : a) o.insert(c);
    return in;
}

std::istream &operator>>(std::istream &in, queue<int> &o) {
    ll a;
    in >> a;
    o.push(a);
    return in;
}

bool contain(set<char> &s, char a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);


typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;


int to_id(int n, int y, int x) {
    return y * n + x;
};

int main() {
    int n;
    cin >> n;


    vector<vector<bool>> board(n, vector<bool>(n));
    rep(y, n) rep(x, n) {
            char c;
            cin >> c;
            board[y][x] = c == '#';
        }

        
    vector<vector<bool>> v(n, vector<bool>(n));

    auto get = [&](int y, int x) -> bool {
        if (y == -1 || y == n || x == -1 || x == n) return false;
        return v[y][x];
    };

    rep(y, n - 1) {
        rep(x, n) {
            bool c = board[y][x];
            bool u = get(y - 1, x);
            bool r = get(y, x + 1);
            bool l = get(y, x - 1);

            bool d = c != u != r != l;
            v[y + 1][x] = d;

        }
    }

    rep(y, n) {
        rep(x, n) cout << (v[y][x] ? '#' : '.');
        cout << endl;
    }


}

