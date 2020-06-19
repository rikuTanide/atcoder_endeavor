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



vector<ll> gf2_rank(vector<ll> &v) {
    int n = v.size();
    rep(i, n) {
        int x = max_element(v.begin() + i, v.end()) - v.begin();
        if (v[x] == 0) break;
        swap(v[i], v[x]);
        ll msb = 1;
        while (msb << 1 <= v[i]) msb <<= 1;
        rep(j, n) if (j != i) if (v[j] & msb) v[j] ^= v[i];
    }
    while (v.size() && v.back() == 0) v.pop_back();
    return v;
}

int main() {
    int n;
    cin >> n;
    vector<ll> v;
    vector<ll> a(n);

    ll x = 0;


    rep(i, n) {
        cin >> a[i];
        x ^= a[i];
    }
    rep(i, n) {
        a[i] &= ~x;
        v.push_back(a[i]);
    }
    gf2_rank(v);
    ll ret = 0;
    for (ll l: v) ret = max(ret, ret ^ l);
    cout << ret * 2 + x << endl;


}