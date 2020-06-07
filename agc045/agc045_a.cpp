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

struct SV {
    vector<ll> v;
    string s;
};

vector<ll> grouping(string s) {
    vector<ll> g(s.size(), -1);
    g[0] = 0;
    for (int i = 1; i < s.size(); i++) {
        if (s[i - 1] == s[i]) g[i] = g[i - 1];
        else g[i] = g[i - 1] + 1;
    }
    return g;
}

SV norm(SV next, vector<ll> g) {
    while (true) {
        bool ok = [&] {
            for (int i = 0; i < next.v.size(); i++) {
                for (int j = i + 1; j < next.v.size(); j++) {
                    if (g[i] != g[j]) break;
                    ll a = next.v[i];
                    ll b = next.v[j];
                    if ((a | b) == a) {
                        next.v[i] = (a - b);
                        return true;
                    } else if ((b | a) == b) {
                        next.v[j] = (b - a);
                        return true;
                    }
                }
            }
            return false;
        }();
        if (ok) continue;
        else break;
    }
    return next;
}

SV find_equal(SV sv) {
    for (int i = 0; i < sv.v.size(); i++) {
        for (int j = i + 1; j < sv.v.size(); j++) {
            if (sv.v[j] == 0) continue;
            if (sv.v[i] == 0) continue;

            if (sv.v[i] == sv.v[j]) {
                sv.v[i] = 0;
                sv.v[j] = 0;
            }
        }
    }
    return sv;
}

SV exclude_zero(SV sv) {
    SV next{vector<ll>(), ""};

    rep(i, sv.v.size()) {
        if (sv.v[i] == 0) continue;
        next.v.push_back(sv.v[i]);
        next.s.push_back(sv.s[i]);
    }
    return next;
}

bool solve(vector<ll> v, string s) {

    SV prev{v, s};

    while (true) {

        assert(prev.v.size() == prev.s.size());

        SV next = prev;
        vector<ll> g = grouping(s);
        next = norm(next, g);
        next = find_equal(next);
        next = exclude_zero(next);

        if (prev.v == next.v) break;
        prev = next;
    }

    if (prev.s.find('1') == -1) return true;
    return false;
}

int main() {
    int t;
    cin >> t;
    rep(_, t) {
        int n;
        cin >> n;

        vector<ll> v(n);
        rep(i, n) cin >> v[i];

        string s;
        cin >> s;

        bool b = solve(v, s);
        cout << (b ? 0 : 1) << endl;
    }
}
