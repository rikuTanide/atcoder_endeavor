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

vector<char> lcs(const string &a, const string &b) {
    const int n = a.size(), m = b.size();
    vector<vector<int> > X(n + 1, vector<int>(m + 1));
    vector<vector<int> > Y(n + 1, vector<int>(m + 1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i] == b[j]) {
                X[i + 1][j + 1] = X[i][j] + 1;
                Y[i + 1][j + 1] = 0;
            } else if (X[i + 1][j] < X[i][j + 1]) {
                X[i + 1][j + 1] = X[i][j + 1];
                Y[i + 1][j + 1] = +1;
            } else {
                X[i + 1][j + 1] = X[i + 1][j];
                Y[i + 1][j + 1] = -1;
            }
        }
    }
    vector<char> c;
    for (int i = n, j = m; i > 0 && j > 0;) {
        if (Y[i][j] > 0) --i;
        else if (Y[i][j] < 0) --j;
        else {
            c.push_back(a[i - 1]);
            --i;
            --j;
        }
    }
    reverse(c.begin(), c.end());
    return c;
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    for (int i = 1; i < n; i++) {
        string a = s.substr(0, i), b = s.substr(i);
        auto v = lcs(a, b);
        ans = max<ll>(ans, v.size());
    }
    cout << n - (ans * 2) << endl;
}
