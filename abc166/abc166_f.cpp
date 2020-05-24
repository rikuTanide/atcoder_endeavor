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
    int n;
    ll a, b, c;
    cin >> n >> a >> b >> c;

    vector<string> method(n);
    rep(i, n) cin >> method[i];

    vector<char> ans;

    rep(i, n) {
        string s = method[i];
        if (s == "AB") {
            if (a + b == 0) {
                cout << "No" << endl;
                ret();
            }
            if (a > b) {
                a--;
                b++;
                ans.push_back('B');
            } else if (a == b && i < n - 1) {
                string t = method[i + 1];
                if (t == "AB") {
                    a--;
                    b++;
                    ans.push_back('B');
                } else if (t == "BC") {
                    a--;
                    b++;
                    ans.push_back('B');
                } else {
                    a++;
                    b--;
                    ans.push_back('A');
                }
            } else {
                a++;
                b--;
                ans.push_back('A');
            }
        } else if (s == "BC") {
            if (b + c == 0) {
                cout << "No" << endl;
                ret();
            }
            if (b > c) {
                b--;
                c++;
                ans.push_back('C');
            } else if (b == c && i < n - 1) {
                string t = method[i + 1];
                if (t == "AB") {
                    c--;
                    b++;
                    ans.push_back('B');
                } else if (t == "BC") {
                    c--;
                    b++;
                    ans.push_back('B');
                } else {
                    c++;
                    b--;
                    ans.push_back('C');
                }
            } else {
                b++;
                c--;
                ans.push_back('B');
            }
        } else {
            if (a + c == 0) {
                cout << "No" << endl;
                ret();
            }
            if (a > c) {
                a--;
                c++;
                ans.push_back('C');
            } else if (a == c && i < n - 1) {
                string t = method[i + 1];
                if (t == "AB") {
                    c--;
                    a++;
                    ans.push_back('A');
                } else if (t == "BC") {
                    c--;
                    a++;
                    ans.push_back('A');
                } else {
                    c++;
                    a--;
                    ans.push_back('C');
                }
            } else {
                a++;
                c--;
                ans.push_back('A');
            }
        }
    }
    cout << "Yes" << endl;
    for (char c : ans) cout << c << endl;

}