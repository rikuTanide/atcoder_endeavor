#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<double, double> P;
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

struct Event {
    ll time, type, value;
};

int main() {
    int n, q;
    cin >> n >> q;

    vector<Event> events;
    rep(i, n) {
        int s, t, x;
        cin >> s >> t >> x;
        Event e1 = {s - x, -1, x};
        Event e2 = {t - x, 0, x};
        events.push_back(e1);
        events.push_back(e2);
    }

    rep(i, q) {
        int d;
        cin >> d;

        Event e = {d, 1, i};
        events.push_back(e);
    }

    sort(events.begin(), events.end(), [](Event &e1, Event &e2) {
        vector<ll>
                a = {e1.time, e1.type, e1.value},
                b = {e2.time, e2.type, e2.value};

        return a < b;
    });

    vector<ll> res(q);

    multiset<ll> se;

    for (auto &p : events) {
        ll x = p.time;
        ll t = p.type;
        ll value = p.value;
        if (t == -1) se.insert(value);
        else if (t == 0) se.erase(se.lower_bound(value));
        else res[value] = (se.empty() ? -1 : *(se.begin()));
    }

    for (auto v : res) cout << v << endl;

}