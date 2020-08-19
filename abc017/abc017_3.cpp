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

struct Iseki {
    int left, right, point;
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<Iseki> isekis(n);
    for (Iseki &iseki : isekis) {
        cin >> iseki.left >> iseki.right >> iseki.point;
        iseki.left--;
        iseki.right--;
    }

    vector<ll> imos(m + 1);
    for (Iseki iseki: isekis) {
        imos[iseki.left] += iseki.point;
        imos[iseki.right + 1] -= iseki.point;
    }

    rep(i, m - 1) {
        imos[i + 1] += imos[i];
    }

    ll sum = accumulate(isekis.begin(), isekis.end(), 0ll, [](ll sum, Iseki i1) {
        return sum + i1.point;
    });
    ll ans = 0;
    rep(i, m) {
        ll now = sum - imos[i];
        cmax(ans, now);
    }
    cout << ans << endl;
}
