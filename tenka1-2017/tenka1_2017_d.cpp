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


bool ctn(ll a, ll b) {
    return (a | b) == a;
}

int main() {
    int n;
    ll k;
    cin >> n >> k;

//    cout << bitset<30>(k) << endl;

    vector<P> v(n);
    for (P &p:v)cin >> p.first >> p.second;
    ll ans = 0;
    for (P p : v) if (ctn(k, p.first)) ans += p.second;

    rep(i, 32) {
        if (!((k >> i) & 1))continue;
        ll l = (k >> (i + 1));
//        cout << bitset<30>(l) << endl;

        ll now = 0;
        for (P p : v) {
            if ((p.first >> i) & 1) continue;
            if (!ctn(l, p.first >> (i + 1)))continue;
            now += p.second;
        }
//        cout << now << endl;
        cmax(ans, now);
    }
    cout << ans << endl;


}