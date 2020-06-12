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

int f(string &s, int l, int r, int k, vector<vector<vector<int>>> &memo) {
    if (memo[l][r][k] != -1) return memo[l][r][k];

    int ans = [&] {

        if (l == r) return 1;
        else if (l + 1 == r) {
            if (s[l] == s[r] || 0 < k) return 2;
            else return 1;
        } else {
            int ans = 0;
            cmax(ans, f(s, l + 1, r, k, memo));
            cmax(ans, f(s, l, r - 1, k, memo));

            if (s[l] == s[r]) cmax(ans, f(s, l + 1, r - 1, k, memo) + 2);
            else if (0 < k) cmax(ans, f(s, l + 1, r - 1, k - 1, memo) + 2);
            return ans;
        }

    }();

    return memo[l][r][k] = ans;
}

int main() {
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();
    vector<vector<vector<int>>> memo(n, vector<vector<int>>(n, vector<int>(n, -1)));
    cout << f(s, 0, n - 1, k, memo) << endl;
}
