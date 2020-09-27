#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;
//#include "atcoder/all"

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
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

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<string> ss(n);
    rep(i, n) cin >> ss[i];

    if (a + b + c == 2) {
        __throw_runtime_error("konaide");
    }
    vector<char> ans;
    for (string s : ss) {
        if (s == "AB") {

            if (a > b) {
                ans.push_back('B');
                b++;
                a--;
            } else {
                ans.push_back('A');
                a++;
                b--;
            }

        } else if (s == "BC") {
            if (b > c) {
                ans.push_back('C');
                c++;
                b--;
            } else {
                ans.push_back('B');
                b++;
                c--;
            }
        } else {
            if (a > c) {
                ans.push_back('C');
                c++;
                a--;
            } else {
                ans.push_back('A');
                a++;
                c--;
            }
        }
        if (a < 0 || b < 0 || c < 0) {
            cout << "No" << endl;
            ret();
        }
    }

    cout << "Yes" << endl;
    for (char c : ans) cout << c << endl;

}
