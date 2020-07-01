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
    vector<ll> v(n);
    rep(i, n) cin >> v[i];
    sort(v.begin(), v.end());

    deque<ll> q;
    for (ll l : v) q.push_back(l);

    list<ll> l;

    int i = 0;
    while (!q.empty()) {

        if (q.size() == 1) {
            if (abs(l.back() - q.front()) > abs(l.front() - q.front())) {
                l.push_back(q.front());
            } else {
                l.push_front(q.front());
            }
            break;
        }

        if (i % 2 == 0) {
            ll f = q.front();
            q.pop_front();
            l.push_back(f);

            ll b = q.back();
            q.pop_back();
            l.push_back(b);
        } else {
            ll f = q.front();
            q.pop_front();
            l.push_back(f);

            ll b = q.back();
            q.pop_back();
            l.push_front(b);
        }
        i++;
    }

    vector<ll> a;
    for (ll j : l) a.push_back(j);
    ll ans = 0;
    rep(i, n - 1) ans += abs(a[i] - a[i + 1]);
    cout << ans << endl;
}
