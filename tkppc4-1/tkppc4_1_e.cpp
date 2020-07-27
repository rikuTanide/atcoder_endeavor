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
    int n, m, k;
    ll e;
    cin >> n >> m >> k >> e;

    vector<ll> as(n);
    rep(i, n) cin >> as[i];

    vector<ll> bs(m);
    rep(i, m) cin >> bs[i];

    ll asum = accumulate(as.begin(), as.end(), 0ll);
    sort(bs.rbegin(), bs.rend());

    ll ne = e - asum;
    if (ne >= 0) {
        cout << "Yes" << endl << 0 << endl;
        ret();
    }

    rep(i, min(m, k)) {
        ne += bs[i];
        if (ne >= 0) {
            cout << "Yes" << endl;
            cout << i + 1 << endl;
            ret();
        }
    }

    ll bsum = accumulate(bs.begin(), bs.begin() + k, 0ll);
    sort(as.begin(), as.end());
    cout << "No" << endl;
    {
        ll ne = bsum + e;
        rep(i, n) {
            if (ne - as[i] < 0) {
                cout << i << endl;
                ret();
            }
            ne -= as[i];
        }
    }

}
