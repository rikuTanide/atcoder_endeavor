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


int main() {
    int n;
    cin >> n;

    vector<ll> rocks(n);
    rep(i, n) cin >> rocks[i];
    map<ll, ll> m;
    for (ll l : rocks) m[l]++;

    vector<int> v;
    v.push_back(0);

    vector<ll> rt(n);

    rep(i, n) if (i > 0) if (rocks[v.back()] < rocks[i]) v.push_back(i);
    for (int i = v.size() - 2; i >= 0; i--) {
        while (m.rbegin()->first > rocks[v[i]]) {
            auto r = *m.rbegin();
            m.erase(r.first);
            rt[v[i + 1]] += (r.first - rocks[v[i]]) * r.second;
            m[rocks[v[i]]] += r.second;
        }
    }

    for (auto e : m) rt[0] += e.first * e.second;

    rep(i, n) cout << rt[i] << endl;

}
