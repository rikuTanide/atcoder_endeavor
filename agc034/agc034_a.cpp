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
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    string s;
    cin >> s;

    a--;
    b--;
    c--;
    d--;

    // a~cの間に二連続岩があるか？
    // b~dの間に二連続岩があるか？
    // D < Cの時にB～Dに二連続平地があるか？

    for (int i = a; i < c; i++) {
        if (s[i] == '#' && s[i + 1] == '#') {
            cout << "No" << endl;
            ret();
        }
    }

    for (int i = b; i < d; i++) {
        if (s[i] == '#' && s[i + 1] == '#') {
            cout << "No" << endl;
            ret();
        }
    }

    if (d < c) {
        for (int i = b; i < d; i++) {
            if (s[i - 1] == '.' && s[i] == '.' && s[i + 1] == '.') {
                cout << "Yes" << endl;
                ret();
            }
        }
        cout << "No" << endl;
        ret();
    } else {
        cout << "Yes" << endl;
    }


}
