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

int main() {
    string s, k;
    cin >> s >> k;

//    set<char> known;
    set<char> unknown;
    string alphabet = "1234567890abcdefghijklmnopqrstuvwxyz";

    for (char c : alphabet) {
        if (find(k.begin(), k.end(), c) == k.end()) unknown.insert(c);
    }

    double ans = 0;
    for (char c : s) {
        if (!contain(unknown, c)) {
            ans += 1;
            continue;
        }

        int uns = unknown.size();
        double cp = 1.0 / uns;
        double wp = 1.0 - cp;

        double now = cp * 1 + wp * 3;
        ans += now;
        unknown.erase(c);
    }

    printf("%.20f\n", ans);
}

