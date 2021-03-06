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
    ll h, w;
    int n;
    cin >> h >> w >> n;

    vector <P> v(n);
    for (P &p:v)cin >> p.first >> p.second;

    ll all = (w - 1) * h + (h - 1) * w;

    for (P p : v) {
        if (p.first != 1) all--;
        if (p.first != h) all--;
        if (p.second != 1) all--;
        if (p.second != w) all--;
    }


    int sub = 0;

    for (P p1: v) {
        for (P p2 : v) {


            ll i = abs(p1.first - p2.first);
            ll j = abs(p1.second - p2.second);
            if (i + j == 1) {
                sub++;
            }
        }
    }

    all += (sub / 2);

    cout << all << endl;


}
