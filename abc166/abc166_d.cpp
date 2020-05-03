#include <bits/stdc++.h>


using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<string> &o) {
    string a;
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

typedef pair<ll, ll> P;

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

ll pow2(ll a) {
    ll b = a;
    b *= a;
    b *= a;
    b *= a;
    b *= a;
    return b;
}


int main() {

    ll x;
    cin >> x;
    vector<P> xs;

    for (ll i = 0; pow2(i) <= 10e17; i++) {
        xs.emplace_back(i, pow2(i));
        xs.emplace_back(-i, pow2(-i));
    }

    for (P a : xs) {
        for (P b : xs) {
            if (a.second - b.second == x) {
                cout << a.first << ' ' << b.first << endl;
                ret();
            }
        }
    }


}