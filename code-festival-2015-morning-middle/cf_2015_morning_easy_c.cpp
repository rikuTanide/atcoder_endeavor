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

int main() {
    ll n, k, m, r;
    cin >> n >> k >> m >> r;


    ll border = r * k;

    vector<ll> tests(n - 1);
    rep(i, n - 1) cin >> tests[i];
    sort(tests.rbegin(), tests.rend());

    if (k == n) {
        ll sum = accumulate(tests.begin(), tests.end(), 0ll);
        if (sum >= border) {
            cout << 0 << endl;
        } else if (sum + m < border) {
            cout << -1 << endl;
        } else {
            cout << border - sum << endl;
        }
    } else {
        ll sum = accumulate(tests.begin(), tests.begin() + k, 0ll);
        ll psum = sum - tests[k - 1];
        if (sum >= border) {
            cout << 0 << endl;
        } else if (psum + m < border) {
            cout << -1 << endl;
        } else {
            cout << border - psum << endl;
        }

    }

}
