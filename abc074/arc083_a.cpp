#include <bits/stdc++.h>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

std::istream &operator>>(std::istream &in, set<ll> &o) {
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

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//const ll mod = 1e10;
//typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;



struct Sol {
    int w, s;
};

bool operator<(const Sol &x, const Sol &y) {
    bool ok = x.s * (y.w + y.s) < y.s * (x.w + x.s);
    return ok;
}

int main() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;


    auto gw = [&](int ai, int bi) -> int {
        int ua = ai * 100 * a;
        int ub = bi * 100 * b;
        return ua + ub;
    };

    auto gs = [&](int ci, int di) -> int {
        int s = ci * c + di * d;
        return s;
    };

    auto g = [&](int ai, int bi, int ci, int di) -> int {
        int w = gw(ai, bi);
        int s = gs(ci, di);
        return w + s;
    };

    auto check_rate = [&](int ai, int bi, int ci, int di) -> bool {
        int w = gw(ai, bi);
        int s = gs(ci, di);
        int t = e * (s + w);
        int u = (100 + e) * s;
        return u <= t;
    };

    Sol ans = {a, 0};

    for (int ai = 0; g(ai, 0, 0, 0) <= f; ai++) {
        for (int bi = 0; g(ai, bi, 0, 0) <= f; bi++) {
            for (int ci = 0; g(ai, bi, ci, 0) <= f && check_rate(ai, bi, ci, 0); ci++) {
                for (int di = 0; g(ai, bi, ci, di) <= f && check_rate(ai, bi, ci, di); di++) {
                    Sol now = {g(ai, bi, ci, di), gs(ci, di)};
                    cmax(ans, now);
                }
            }
        }
    }
    cout << ans.w << ' ' << ans.s << endl;

}