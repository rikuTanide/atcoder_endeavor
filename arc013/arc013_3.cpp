#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<double, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<int> &o) {
    ll a;
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
    vector<ll> nim;
    rep(i, n) {
        ll x, y, z, m;
        cin >> x >> y >> z >> m;

        vector<ll> xs(m), ys(m), zs(m);

        rep(j, m) {
            cin >> xs[j] >> ys[j] >> zs[j];
        }

        ll l = *min_element(xs.begin(), xs.end());
        ll r = x - *max_element(xs.begin(), xs.end()) - 1;

        ll t = *min_element(ys.begin(), ys.end());
        ll b = y - *max_element(ys.begin(), ys.end()) - 1;

        ll n = *min_element(zs.begin(), zs.end());
        ll f = z - *max_element(zs.begin(), zs.end()) - 1;

        nim.push_back(l);
        nim.push_back(r);
        nim.push_back(t);
        nim.push_back(b);
        nim.push_back(n);
        nim.push_back(f);
    }

    ll all = 0;
    for (ll l : nim) all ^= l;

    if (all != 0) {
        cout << "WIN" << endl;
    } else {
        cout << "LOSE" << endl;
    }

}

