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
    vector<P> v(n);

    for (P &p:v)cin >> p.first >> p.second;
    sort(v.begin(), v.end(), [](P p1, P p2) {

        if (p1.first != p2.first) {
            return p1.first < p2.first;
        }

        return p1.second > p2.second;
    });

    map<ll, ll> m;

    auto get_smaller = [&](ll h) -> int {
        auto it = m.lower_bound(h);
        if (it == m.begin()) {
            return 0;
        }

        it--;
        return (*it).second;
    };

    auto add = [&](ll h, int value) {
        // 下より大きい義務がある
        if (m.upper_bound(h) == m.begin()) {
            m[h] = value;
        } else {
            auto it = m.upper_bound(h);
            it--;
            if ((*it).second < value) {
                m[h] = value;
            }
        }

        vector<ll> del;
        for (auto it = m.upper_bound(h); it != m.end() && (*it).second <= value; it++) {
            del.push_back((*it).first);
        }
        for (ll key : del) m.erase(m.find(key));

    };

    for (P p : v) {
        int small = get_smaller(p.second);
        add(p.second, small + 1);
    }

    ll ans = 0;
    for (auto e : m) {
        cmax(ans, e.second);
    }
    cout << ans << endl;

}
