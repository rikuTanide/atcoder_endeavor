#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
//typedef long long ll;
typedef mp::cpp_int  ll;
const long double EPS = 1e-9;

#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
//const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;
/*
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
*/
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;

int main() {
    int n;
    cin >> n;

    vector<ll> sizes(n + 1);
    rep(i, n + 1) cin >> sizes[i];

    if (sizes[0] == 1) {
        if (n == 0) {
            cout << 1 << endl;
            ret();
        } else {
            cout << -1 << endl;
            ret();
        }
    }


    if (sizes.back() == 0) {
        cout << -1 << endl;
        ret();
    }

//
    vector<P> mas(n + 1);
    mas[0] = P(1, 0);

    rep(i, n + 1) {
        if (i == 0) continue;
        ll ma = mas[i - 1].first * 2;
        ll s = sizes[i];
        mas[i] = P(ma - s, s);
    }

    vector<P> mis(n + 1);
    mis[n] = P(0, sizes[n]);
    for (int i = n - 1; i >= 0; i--) {
        ll mi = mis[i + 1].first + mis[i + 1].second;
        mis[i] = P(mi, sizes[i]);
        if (mis[i].first > mas[i].first) {
            mis[i].first = mas[i].first;
        }
    }

    for (P p : mas) {
        if (p.first < 0) {
            cout << -1 << endl;
            ret();
        }
    }
    rep(i, n) {
        if (mis[i].first * 2 < mis[i + 1].first + mis[i + 1].second) {
            cout << -1 << endl;
            ret();
        }
    }


    ll ans = 0;
    for (P p : mis) ans += (p.first + p.second);

    cout << ans << endl;


}
