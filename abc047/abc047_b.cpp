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

int check(int t, vector<int> &v) {
    int ans = 0;
    for (int i : v) ans += (i - t) * (i - t);
    return ans;
}

int main() {
    int w, h, n;
    cin >> w >> h >> n;

    int l = 0, r = w, u = h, d = 0;

    rep(_, n) {
        int x, y, a;
        cin >> x >> y >> a;


        if (a == 1) {
            // 左
            cmax(l, x);
        } else if (a == 2) {
            // 右
            cmin(r, x);
        } else if (a == 3) {
            // 下
            cmax(d, y);
        } else {
            cmin(u, y);
        }
    }

    if (r <= l || u <= d) {
        cout << 0 << endl;
    } else {
        int width = r - l;
        int height = u - d;
        cout << width * height << endl;
    }

}
