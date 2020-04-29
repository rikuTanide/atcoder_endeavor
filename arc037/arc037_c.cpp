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

int smaller(vector<ll> &v, ll x) {
    auto begin = v.begin();
    auto end = v.end();

    return distance(begin, lower_bound(begin, end, x));
}

bool check(vector<ll> &v1, vector<ll> &v2, ll mid, ll k) {
    ll sum = 0;
    for (ll a : v1) {
        ll t = (mid + a - 1) / a;
        ll m = smaller(v2, t);
        sum += m;
    }
    return sum < k;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<ll> v1(n), v2(n);
    rep(i, n) cin >> v1[i];
    rep(i, n) cin >> v2[i];

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    ll floor = 0, ceil = LONG_LONG_MAX;
    while (floor + 1 < ceil) {
        ll mid = (floor + ceil) / 2;
        bool b = check(v1, v2, mid, k);
        if (b) floor = mid;
        else ceil = mid;
    }
    cout << floor << endl;
}