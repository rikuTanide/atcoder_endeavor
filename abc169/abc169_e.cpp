#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const long double EPS = 1e-9;

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

std::istream &operator>>(std::istream &in, set<char> &o) {
    string a;
    in >> a;
    for (char c : a) o.insert(c);
    return in;
}

std::istream &operator>>(std::istream &in, queue<int> &o) {
    ll a;
    in >> a;
    o.push(a);
    return in;
}

bool contain(set<char> &s, char a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;


int main() {
    int n;
    cin >> n;

    vector<ll> l(n), r(n);
    rep(i, n) cin >> l[i] >> r[i];

    sort(l.begin(), l.end());
    sort(r.begin(), r.end());

    auto get_med = [&](vector<ll> &v) -> ll {
        if (n % 2 == 0) {
            int i = n / 2;
            int j = i - 1;
            return v[i] + v[j];
        } else {
            int i = n / 2;
            return v[i] + v[i];
        }
    };

    ll lm = get_med(l), rm = get_med(r);


    if (n % 2 == 0) {
        ll ans = rm - lm + 1;
        cout << ans << endl;
    } else {
        ll ans = rm - lm + 2;
        cout << ans / 2 << endl;
    }

}