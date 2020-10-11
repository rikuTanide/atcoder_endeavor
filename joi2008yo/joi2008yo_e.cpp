#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;
//#include "atcoder/all"

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
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

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

vector<bool> turn(vector<bool> &v) {
    vector<bool> res(v.size());
    rep(i, v.size()) res[i] = !v[i];
    return res;
}

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<bool>> plate(h, vector<bool>(w));

    rep(y, h) {
        rep(x, w) {
            int i;
            cin >> i;
            plate[y][x] = i == 1;
        }
    }
    int ans = 0;

    rep(i, 1 << h) {
        vector<vector<bool>> tmp = plate;

        rep(j, h) {
            if ((i >> j) & 1) tmp[j] = plate[j];
            else tmp[j] = turn(plate[j]);
        }

        vector<vector<int>> count(w, vector<int>(2, 0));
        rep(y, h) {
            rep(x, w) {
                if (tmp[y][x]) count[x][0]++;
                else count[x][1]++;
            }
        }

        int now = 0;
        for (vector<int> u : count) now += max(u[0], u[1]);
        cmax(ans, now);
    }
    cout << ans << endl;
}
