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

int count_pair(vector<ll> &u) {
    map<int, int> m;
    for (ll t : u) m[t]++;

    int ans = 0;
    for (auto e : m) {
        ans += (e.second) / 2;
    }
    return ans;

}

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> v(n);
    rep(i, n) cin >> v[i];

    vector<vector<ll>> u(m);
    rep(i, n) {
        ll s = v[i];
        ll t = (s % m);
        u[t].push_back(s);
    }

    int ans = 0;
    rep(i, m) {
        int j = m - i;
        if (i > j) continue;
        if (i == j || i == 0) {
            int now = u[i].size() / 2;
            ans += now;
        } else {
            int uis = u[i].size();
            int ujs = u[j].size();
            if (uis > ujs) {
                int p = count_pair(u[i]);
                int sp = min((uis - ujs) / 2, p);

                int now = sp + ujs;
                ans += now;
            } else {
                int p = count_pair(u[j]);
                int sp = min((ujs - uis) / 2, p);

                int now = sp + uis;
                ans += now;
            }

        }
    }

    cout << ans << endl;
}
