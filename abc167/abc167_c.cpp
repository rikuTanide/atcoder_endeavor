#include <bits/stdc++.h>

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

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;


struct Book {
    ll price;
    vector<ll> points;
};


int main() {
    ll n, m, x;
    cin >> n >> m >> x;

    vector<Book> books(n);
    rep(i, n) {
        cin >> books[i].price;
        books[i].points = vector<ll>(m);
        rep(j, m) cin >> books[i].points[j];
    }

    ll ans = INF;
    rep(i, 1 << n) {
        vector<ll> points(m);
        ll price = 0;
        rep(j, n) {
            bool b = (i >> j) & 1;
            if (!b) continue;
            rep(k, m) points[k] += books[j].points[k];
            price += books[j].price;
        }

        ll p = *min_element(points.begin(), points.end());
        if (p < x) continue;
        cmin(ans, price);
    }
    cout << ans << endl;
}
