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
    int n;
    cin >> n;

    vector<ll> numbers(n);
    rep(i, n) cin >> numbers[i];

    map<ll, ll> m;
    rep(i, n) m[numbers[i]] = i;

    set<int> used;
    ll ans = 0;
    for (int i = n; i >= 1; i--) {
        int j = m[i];
        int r1 = [&] {
            auto it = used.lower_bound(j);
            if (it == used.end()) return n;
            return *it;
        }();

        int r2 = [&] {
            auto it = used.lower_bound(j);
            if (it == used.end()) return n;
            it++;
            if (it == used.end()) return n;
            return *it;
        }();

        int l1 = [&] {
            auto it = used.lower_bound(j);
            if (it == used.begin()) return -1;
            it--;
            return *it;
        }();

        int l2 = [&] {
            auto it = used.lower_bound(j);
            if (it == used.begin()) return -1;
            it--;
            if (it == used.begin()) return -1;
            it--;
            return *it;
        }();

        ll k1 = (l1 - l2) * (r1 - j);
        ll k2 = (r2 - r1) * (j - l1);

        ll now = i * k1 + i * k2;

        ans += now;

        used.insert(j);

    }
    cout << ans << endl;
}
