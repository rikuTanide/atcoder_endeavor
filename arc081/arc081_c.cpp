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

vector<vector<int>> calcNext(string &s) {
    int n = s.size();
    vector<vector<int>> res(n + 2, vector<int>(26, n + 1));

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) res[i][j] = res[i + 1][j];
        res[i][s[i] - 'a'] = i;
    }

    return res;
}

template<class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

string solve(string s) {
    int n = s.size();
    auto next = calcNext(s);
    vector<int> dp(n + 1, 1 << 29);
    vector<char> recon(n + 1, 'a');
    dp[n] = 1;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            if (next[i][j] == n + 1) {
                if (dp[i] > 1) {
                    dp[i] = 1;
                    recon[i] = 'a' + j;
                }
            } else if (chmin(dp[i], dp[next[i][j] + 1] + 1)) {
                recon[i] = 'a' + j;
            }
        }
    }


    string res = "";
    int index = 0;
    while (index <= n) {
        res += recon[index];
        index = next[index][recon[index] - 'a'] + 1;
    }
    return res;
}

int main() {
    string s;
    cin >> s;

    cout << solve(s) << endl;
}
