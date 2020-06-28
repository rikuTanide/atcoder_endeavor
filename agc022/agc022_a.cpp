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
    string s;
    cin >> s;
    int n = s.size();
    if (n < 26) {
        set<char> ss;
        rep(i, 26) ss.insert('a' + i);
        for (char c : s) ss.erase(c);

        string t = s + char(*ss.begin());
        cout << t << endl;
        ret();
    }

    if (s == "zyxwvutsrqponmlkjihgfedcba") {
        cout << -1 << endl;
        ret();
    }

    vector<int> v(26);
    rep(i, n) v[i] = s[i] - 'a';

    next_permutation(v.begin(), v.end());

    int q = [&] {
        rep(i, n) if (s[i] - 'a' != v[i]) return i;
        __throw_runtime_error("konaide");
    }();

//    cout << char(v[q] + 'a') << endl;

    rep(i, q + 1) cout << char(v[i] + 'a');


    cout << endl;
}
