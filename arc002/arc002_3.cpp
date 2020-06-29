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

int check(int n, string l, string r, string &s) {
//    if(l == "AB" && r == "XY") {
//        cout << endl;
//    }
    vector<int> dp(n, INT_MAX);

    auto get_sub = [&](int i) -> string {
        if (i < 1) return "";
        string t = s.substr(i - 1, 2);
//        cout << t << endl;
        return t;
    };

    auto get = [&](int i) {
        if (i < 0) {
            return 0;
        }
        return dp[i];
    };

    rep(i, n) {
        cmin(dp[i], get(i - 1) + 1);
        if (get_sub(i) == l) {
            cmin(dp[i], get(i - 2) + 1);
        }
        if (get_sub(i) == r) {
            cmin(dp[i], get(i - 2) + 1);
        }
    }
    return dp.back();
}

int main() {
    vector<char> abxy = {'A', 'B', 'X', 'Y'};

    int n;
    string s;
    cin >> n >> s;

    int ans = INT_MAX;

    for (char l1 : abxy) {
        for (char l2 : abxy) {
            for (char r1 : abxy) {
                for (char r2 : abxy) {
                    string l = "";
                    l.push_back(l1);
                    l.push_back(l2);
                    string r = "";
                    r.push_back(r1);
                    r.push_back(r2);

                    int now = check(n, l, r, s);
                    cmin(ans, now);
                }
            }
        }
    }
    cout << ans << endl;
}
