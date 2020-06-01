#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const long double EPS = 1e-9;

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

    string s;
    cin >> s;

    map<int, int> prev;
    prev[0] = 0;
    int n = s.size();
    rep(i, n) {
        char c = s[i];
        map<int, int> next;

        auto cm = [&](int i, int v) {
            if (next.find(i) == next.end()) {
                next[i] = v;
            } else {
                cmax(next[i], v);
            }
        };

        for (auto &e : prev) {

            if (c == '+') {
                cm(e.first, prev[e.first] + e.first);
            } else if (c == '-') {
                cm(e.first, prev[e.first] - e.first);
            } else {
                cm(e.first + 1, prev[e.first]);
                cm(e.first - 1, prev[e.first]);
            }

        }

        prev = next;
    }

    cout << prev[0] << endl;

}
