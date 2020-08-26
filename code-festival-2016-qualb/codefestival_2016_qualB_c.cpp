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

struct Task {
    char direction;
    ll cost;
};

int main() {
    ll w, h;
    cin >> w >> h;
    vector<ll> horizontal(w);
    vector<ll> vertical(h);
    rep(i, w) cin >> horizontal[i];
    rep(i, h) cin >> vertical[i];
    vector<Task> task;
    for (ll c : horizontal) task.push_back({'h', c});
    for (ll c : vertical) task.push_back({'v', c});

    sort(task.begin(), task.end(), [](Task t1, Task t2) {
        return t1.cost < t2.cost;
    });

    ll a = w + 1, b = h + 1;

    ll ans = 0;
    for (Task t : task) {
        if (t.direction == 'h') {
            ll now = b * t.cost;
            a--;
            ans += now;
        } else {
            ll now = a * t.cost;
            b--;
            ans += now;
        }
    }
    cout << ans << endl;

}
