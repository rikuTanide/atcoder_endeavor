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

struct Boy {
    ll salary, border;
};

struct Girl {
    ll salary, border;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Boy> boys(n);
    vector<Girl> girls(m);
    for (Boy &b : boys) cin >> b.salary >> b.border;
    for (Girl &g : girls) cin >> g.salary >> g.border;

    sort(boys.rbegin(), boys.rend(), [](Boy b1, Boy b2) {
        return b1.salary < b2.salary;
    });

    sort(girls.rbegin(), girls.rend(), [](Girl g1, Girl g2) {
        return g1.border < g2.border;
    });

    int ans = 0;

    while (!boys.empty() && !girls.empty()) {
        Boy b = boys.back();
        Girl g = girls.back();
        if (b.salary >= g.border) {
            ans++;
            boys.pop_back();
            girls.pop_back();

            assert(b.border <= g.salary);

        } else {
            boys.pop_back();
        }
    }

    cout << ans << endl;

}