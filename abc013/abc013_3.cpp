#include <bits/stdc++.h>

const double PI = 3.14159265358979323846;
using namespace std;
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

std::istream &operator>>(std::istream &in, set<int> &o) {
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
const int mod = 1000000007;
//const ll mod = 1e10;
typedef priority_queue<string, vector<string>, greater<string> > PQ_ASK;


int main() {

    ll nichi, shoki;

    ll f_yen, f_manzoku, s_yen, s_manzoku, heri;
    cin >> nichi >> shoki >> f_yen >> f_manzoku >> s_yen >> s_manzoku >> heri;

    ll ans = INF;

    rep(i, nichi + 1) {
        ll f_kai = i;
        ll bunshi = -(shoki + f_kai * f_manzoku - nichi * heri + f_kai * heri);
        ll bunbo = s_manzoku + heri;
        ll s_kai = bunshi / bunbo + 1;
        if (s_kai < 0) {
            ll cost = f_kai * f_yen;
            cmin(ans, cost);
            ret();
        }
        if (s_kai + f_kai > nichi) continue;

        ll cost = f_kai * f_yen + s_kai * s_yen;
        cmin(ans, cost);
    }
    assert(ans != INF);
    cout << ans << endl;

}
