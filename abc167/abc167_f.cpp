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

string normalize(string s) {
    string t = "";
    for (char c : s) {
        if (t.empty()) t.push_back(c);
        else if (c == '(') t.push_back(c);
        else if (c == ')' && t.back() == '(') t.pop_back();
        else t.push_back(c);
    }
    return t;
}

int main() {
    int n;
    cin >> n;
    vector<string> ss(n);
    rep(i, n) cin >> ss[i], ss[i] = normalize(ss[i]);

    vector<P> ts(n);
    rep(i, n) ts[i].first = count(ss[i].begin(), ss[i].end(), ')');
    rep(i, n) ts[i].second = count(ss[i].begin(), ss[i].end(), '(');

    vector<P> l, r;

    for (P p : ts) p.first <= p.second ? l.push_back(p) : r.push_back(p);

    sort(l.begin(), l.end(), [](P p1, P p2) {
        return p1.first < p2.first;
    });
    sort(r.rbegin(), r.rend(), [](P p1, P p2) {
        return p1.second < p2.second;
    });

    string s = "";

    for (P p : l) {
        rep(i, p.first) s.push_back(')');
        rep(i, p.second) s.push_back('(');
    }

    for (P p : r) {
        rep(i, p.first) s.push_back(')');
        rep(i, p.second) s.push_back('(');
    }

    string t = normalize(s);
    string ans = t.empty() ? "Yes" : "No";
    cout << ans << endl;
}
