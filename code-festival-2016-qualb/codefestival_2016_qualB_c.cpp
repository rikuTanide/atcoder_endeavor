#include <bits/stdc++.h>


using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<string> &o) {
    string a;
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

typedef pair<ll, ll> P;

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

struct Cost {
    ll cost;
    char direction;
};

std::istream &operator>>(std::istream &in, Cost &o) {
    cin >> o.cost;
    return in;
}


// http://ncastar.hatenablog.com/entry/2016/10/12/224425
int main() {
    ll w, h;
    cin >> w >> h;

    vector<Cost> costs_w(w), costs_h(h);
    rep(i, w) cin >> costs_w[i], costs_w[i].direction = 'v';
    rep(i, h) cin >> costs_h[i], costs_h[i].direction = 'h';

    vector<Cost> costs(w + h);
    rep(i, w) costs[i] = costs_w[i];
    rep(i, h) costs[i + w] = costs_h[i];

    sort(costs.begin(), costs.end(), [&](Cost &c1, Cost &c2) { return c1.cost < c2.cost; });

    ll ans = 0;

    ll used_h = 0, used_w = 0;
    for (Cost cost : costs) {
        if (cost.direction == 'v') {
            ll r = (h + 1) - used_h;
            ll now = r * cost.cost;
            ans += now;
            used_w++;
        } else {
            ll r = (w + 1) - used_w;
            ll now = r * cost.cost;
            ans += now;
            used_h++;
        }
    }
    cout << ans << endl;


}
