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

map<pair<string, string>, ll> f(string &u, int n) {
    map<pair<string, string>, ll> m;
    rep(i, 1 << n) {
        string x = "", y = "";
        rep(j, n) {
            bool b = (i >> j) & 1;
            if (b) x.push_back(u[j]);
            else y.push_back(u[j]);
        }
        m[pair<string, string>(x, y)]++;
    }
    return m;
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    string u = s.substr(0, n);
    string v = s.substr(n);
    reverse(v.begin(), v.end());

    map<pair<string, string>, ll> a = f(u, n), b = f(v, n);


    ll ans = 0;
    for (auto &e : a) {
        pair<string, string> k = e.first;
        ll ai = e.second, bi = b[k];
        ll now = ai * bi;
        ans += now;
    }
    cout << ans << endl;

}
