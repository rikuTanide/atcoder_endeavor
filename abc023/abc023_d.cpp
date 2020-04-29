#include <bits/stdc++.h>

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

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

struct Balloon {
    ll ini, speed;
};

std::istream &operator>>(std::istream &in, Balloon &o) {
    cin >> o.ini >> o.speed;
    return in;
}

bool check(vector<Balloon> &v, ll mid, int n) {
    vector<ll> limits;
    for (Balloon &b : v) {
        ll t = mid - b.ini;
        if (t < 0) return false;
        ll limit = t / b.speed;
        limits.push_back(limit);
    }
    sort(limits.begin(), limits.end());
    rep(i, n) {
        if (limits[i] < i) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<Balloon> v(n);
    rep(i, n) cin >> v[i];


    ll floor = 0, ceil = INF;
    while (floor + 1 < ceil) {
        ll mid = (floor + ceil) / 2;
        bool b = check(v, mid, n);
        if (b) ceil = mid;
        else floor = mid;
    }
    cout << ceil << endl;
}
