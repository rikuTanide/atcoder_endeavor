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

const string IMPOSSIBLE = "Impossible";
const string POSSIBLE = "Possible";

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    rep(i, n) cin >> v[i];

    int ma = *max_element(v.begin(), v.end());
    int ma_count = count(v.begin(), v.end(), ma);
    if (ma_count < 2) {
        cout << IMPOSSIBLE << endl;
        ret();
    }

    vector<int> t(ma + 1, 0);
    for (int i : v) t[i]++;

    set<int> enable;
    for (int i = 0; i <= ma; i++) {
        int l = max(i, ma - i);
        t[l]--;
        enable.insert(l + 1);
    }

    rep(i, ma + 1) {
        if (t[i] < 0) {
            cout << IMPOSSIBLE << endl;
            ret();
        }
        if (t[i] == 0) continue;
        if (contain(enable, i)) continue;
        cout << IMPOSSIBLE << endl;
        ret();
    }

    cout << POSSIBLE << endl;
}
