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


int main() {
    int n;
    cin >> n;
    vector<ll> numbers(n);
    rep(i, n) cin >> numbers[i];
    vector<ll> indexes(n);
    rep(i, n) indexes[numbers[i] - 1] = i;
    vector<ll> as(n), bs(n);
    rep(i, n) {
        ll r = indexes[i];
        ll a = 30000 * (i + 1);
        ll b = 30000 * (n - (i + 1)) + r + 1;
        as[i] = a;
        bs[i] = b;
    }

    rep (i, n) {
        cout << as[i];
        if (i != n - 1) cout << ' ';
    }
    cout << endl;
    rep (i, n) {
        cout << bs[i];
        if (i != n - 1) cout << ' ';
    }
    cout << endl;
}
