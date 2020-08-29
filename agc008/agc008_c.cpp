#include <bits/stdc++.h>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
typedef pair<double, ll> P;
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


int main() {

    ll i, o, t, j, l, s, z;
    cin >> i >> o >> t >> j >> l >> s >> z;

    ll ans = 0;
    ans += o;

    ll ilj = min({i, l, j});

    ll iljc = ilj * 3;
    ans += iljc;

    i -= ilj;
    l -= ilj;
    j -= ilj;

    ll l2 = (l / 2) * 2;
    ll j2 = (j / 2) * 2;
    ll i2 = (i / 2) * 2;

    ans += l2;
    ans += j2;
    ans += i2;
    cout << ans << endl;


}