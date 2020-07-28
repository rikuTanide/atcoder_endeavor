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
    int n, k;
    cin >> n >> k;

    vector<int> mtc(k);
    rep(i, k) cin >> mtc[i], mtc[i]--;

    vector<string> strs(n);
    rep(i, n) cin >> strs[i];

    vector<string> mss(k);
    rep(i, k)mss[i] = strs[i];

    sort(strs.begin(), strs.end());
    sort(mss.begin(), mss.end());

    string start = mss.front(), end = mss.back();

    int ml = [&] {
        int n = min(start.size(), end.size());
        rep(i, n) {
            if (start[i] == end[i]) continue;
            return i;
        }
        return n;
    }();

    rep(l, ml + 1) {
        assert(start.substr(0, l) == end.substr(0, l));
        string mt = start.substr(0, l);
        auto b = lower_bound(strs.begin(), strs.end(), mt);
        auto e = lower_bound(strs.begin(), strs.end(), mt + '~');

        int size = distance(b, e);
        if (size == k) {
            cout << mt << endl;
            ret();
        }

    }
    cout << -1 << endl;

}
