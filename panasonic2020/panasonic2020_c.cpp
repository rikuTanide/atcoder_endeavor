#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep(i, n) for (ll i = 0; i < (n); ++i)
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

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//const ll mod = 1e10;
typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;


int main() {
    cout << sqrt(2) + sqrt(3) << ' ' << sqrt(9) ;
    ll a, b, c;
    cin >> a >> b >> c;
    if (c - a - b <= 0) {
        cout << "No" << endl;
        ret();
    }
    ll aa = a * a;
    ll bb = b * b;
    ll cc = c * c;
    ll ab = a * b;
    ll bc = b * c;
    ll ca = c * a;

    ll l = ab + ab;
    ll r = aa + ab + ab - ca - ca + bb - bc - bc + cc;
    if (l < r) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
