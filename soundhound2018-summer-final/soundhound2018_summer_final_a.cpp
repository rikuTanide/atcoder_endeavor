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


int main() {

    vector<P> ks;

    ll l = 140, r = 170;

    rep(i, 55) {
        ll tl = l * (1ll << i);
        ll tr = r * (1ll << i);

        ks.push_back({tl, tr - 1});

    }

//    for (P p : ks) {
//        cout << p.first << ' ' << p.second << endl;
//    }

    ll c, d;
    cin >> c >> d;
    d--;

    vector<ll> as;
    for (P p : ks) {
        if (p.first <= c && d <= p.second) {
            as.push_back(d - c + 1);
        } else if (c <= p.first && p.second <= d) {
            as.push_back(p.second - p.first + 1);
        } else if (c <= p.first && p.first <= d && d <= p.second) {
            as.push_back(d - p.first + 1);
        } else if (p.first <= c && c <= p.second && p.second <= d) {
            as.push_back(p.second - c + 1);
        }
    }

    ll ans = accumulate(as.begin(), as.end(), 0ll);
    cout << ans << endl;

}