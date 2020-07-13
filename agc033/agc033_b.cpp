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
    int h, w, n, sy, sx;
    cin >> h >> w >> n >> sy >> sx;

    sy--;
    sx--;

    string s, t;
    cin >> s >> t;

    int l = 0, r = w - 1, u = h - 1, d = 0;


    for (int i = n - 1; i >= 0; i--) {
        {
            char c = t[i];
            if (c == 'U') {
                d = max(d - 1, 0);
            } else if (c == 'D') {
                u = min(u + 1, h - 1);
            } else if (c == 'R') {
                l = min(l - 1, 0);
            } else {
                r = max(r + 1, w - 1);
            }
        }

        {
            char c = s[i];
            if (c == 'U') {
                u--;
            } else if (c == 'D') {
                d++;
            } else if (c == 'R') {
                r--;
            } else {
                l++;
            }
        }

        if (r < l || u < d) {
            cout << "NO" << endl;
            ret();
        }

    }

    if (l <= sx && sx <= r && d <= sy && sy <= u) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

}
