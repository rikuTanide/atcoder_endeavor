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


void tow(vector<string> &ss, int n, int a, int b, int c) {
    vector<set<vector<int>>> dp(n + 1);
    dp[0].insert({a, b, c});

    auto add = [&](int i, int a, int b, int c) {
        if (a < 0 || b < 0 || c < 0) return;
        dp[i].insert({a, b, c});
    };

    rep(i, n) {
        string s = ss[i];

        for (auto k : dp[i]) {

            if (s == "AB") {
                add(i + 1, k[0] + 1, k[1] - 1, k[2]);
                add(i + 1, k[0] - 1, k[1] + 1, k[2]);
            } else if (s == "AC") {
                add(i + 1, k[0] + 1, k[1], k[2] - 1);
                add(i + 1, k[0] - 1, k[1], k[2] + 1);
            } else if (s == "BC") {
                add(i + 1, k[0], k[1] + 1, k[2] - 1);
                add(i + 1, k[0], k[1] - 1, k[2] + 1);
            }

        }

    }

    if (dp.back().empty()) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        vector<char> ans;
        vector<int> now = *dp.back().begin();

        auto can = [&](int i, vector<int> &next) -> bool {
            return dp[i].find(next) != dp[i].end();
        };

        for (int i = n - 1; i >= 0; i--) {
            string s = ss[i];
            if (s == "AB") {
                vector<int> ab = {now[0] + 1, now[1] - 1, now[2]};
                vector<int> ba = {now[0] - 1, now[1] + 1, now[2]};
                if (can(i, ab)) {
                    ans.push_back('B');
                    now = ab;
                } else if (can(i, ba)) {
                    ans.push_back('A');
                    now = ba;
                } else {
                    __throw_runtime_error("okasii");
                }
            } else if (s == "BC") {
                vector<int> bc = {now[0], now[1] + 1, now[2] - 1};
                vector<int> cb = {now[0], now[1] - 1, now[2] + 1};
                if (can(i, bc)) {
                    ans.push_back('C');
                    now = bc;
                } else if (can(i, cb)) {
                    ans.push_back('B');
                    now = cb;
                } else {
                    __throw_runtime_error("okasii");
                }
            } else {
                vector<int> ac = {now[0] + 1, now[1], now[2] - 1};
                vector<int> ca = {now[0] - 1, now[1], now[2] + 1};

                if (can(i, ac)) {
                    ans.push_back('C');
                    now = ac;
                } else if (can(i, ca)) {
                    ans.push_back('A');
                    now = ca;
                } else {
                    __throw_runtime_error("okasii");
                }
            }
        }
        reverse(ans.begin(), ans.end());
        for (char c : ans) cout << c << endl;
    }

}

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<string> ss(n);
    rep(i, n) cin >> ss[i];

    if (a + b + c == 2) {
        tow(ss, n, a, b, c);
        ret();
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

