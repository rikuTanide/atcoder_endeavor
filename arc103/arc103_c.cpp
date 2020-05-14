#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
//typedef pair<double, double> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<string> &o) {
    string a;
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
    if (s.back() == '1') {
        cout << -1 << endl;
        ret();
    }
    if (s.front() == '0') {
        cout << -1 << endl;
        ret();
    }
    for (int i = 1; i <= n - 1; i++) {
        if (s[i - 1] != s[n - 1 - i]) {
            cout << -1 << endl;
            ret();
        }
    }

    s[n - 1] = '1';
    int pre = n;
    for (int i = n - 1; i >= 1; i--) {
        cout << i << ' ' << pre << ' ' << endl;
        if (s[i - 1] == '1') pre = i;
    }

}
