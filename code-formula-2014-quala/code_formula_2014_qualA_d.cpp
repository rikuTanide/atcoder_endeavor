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

std::istream &operator>>(std::istream &in, set<char> &o) {
    string a;
    in >> a;
    for (char c : a) o.insert(c);
    return in;
}

std::istream &operator>>(std::istream &in, queue<int> &o) {
    ll a;
    in >> a;
    o.push(a);
    return in;
}

bool contain(set<char> &s, char a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);


typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;

double rec(string &s, set<char> &known, set<char> &unknown, int i) {
    if (i == s.size()) return 0;
    char c = s[i];
    if (contain(known, c)) return rec(s, known, unknown, i + 1) + 1;

    double uks = unknown.size();
    double ans = 0;

    string it = "";
    for (char pc : unknown) it.push_back(pc);

    for (char nc : it) {

        if (nc == c) {
            known.insert(nc);
            unknown.erase(nc);
            double now = 1.0 + rec(s, known, unknown, i + 1);
            ans += (now / uks);

            known.erase(nc);
            unknown.insert(nc);
        } else {
            known.insert(nc);
            unknown.erase(nc);

            double now = 2.0 + rec(s, known, unknown, i);
            ans += (now / uks);

            known.erase(nc);
            unknown.insert(nc);
        }
    }
    return ans;

}

int main() {
    string s, k;
    cin >> s >> k;

    set<char> known;
    set<char> unknown;
    string alphabet = "1234567890abcdefghijklmnopqrstuvwxyz";
    for (char c : alphabet) {
        if (find(k.begin(), k.end(), c) == k.end()) unknown.insert(c);
        else known.insert(c);
    }


    cout << rec(s, known, unknown, 0) << endl;

}

