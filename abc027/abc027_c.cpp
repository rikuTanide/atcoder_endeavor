#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
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

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

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

const int mod = 1000000007;

bool calc(int x, int n, bool b) {
    if (2 * x > n) {
        return !b;
    }
    if (calc(2 * x, n, !b) == b || calc(2 * x + 1, n, !b) == b) {
        return b;
    }
    return !b;
}

string calc2(ll n) {
    if (n == 1) return "Aoki";
    ll x = 1;
    ll k = 4;

    while (true) {
        x += k;
        if (n <= x) {
            return "Takahashi";
        }
        x += k;
        if (n <= x) {
            return "Aoki";
        }
        k *= 4;
    }
}

int main() {
    ll n;
    cin >> n;
    cout << calc2(n) << endl;
}

