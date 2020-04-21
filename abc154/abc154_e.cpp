#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<int> &o) {
    ll a;
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

ll digit_dp(string s, int t) {
    const int DIGIT_MAX = 200;
    vector<vector<vector<vector<ll>>>> dp(DIGIT_MAX,
                                          vector<vector<vector<ll>>>(2, vector<vector<ll>>(10, vector<ll>(t + 1, 0))));
    vector<ll> digits(DIGIT_MAX);
    reverse(s.begin(), s.end());
    rep(i, s.size()) {
        digits[i] = s[i] - '0';
    }
    reverse(digits.begin(), digits.end());

    int first_i = 0, first_j = 0;
    rep(i, DIGIT_MAX) {
        if (digits[i] == 0) continue;
        first_i = i;
        first_j = digits[i];
        break;
    }
    rep(i, 10) {
        if (i == 0) continue;
        if (i < first_j) dp[first_i][true][i][1] = 1;
    }
    dp[first_i][false][first_j][1] = 1;

    // sより小さいことが......

    for (int i = first_i; i < DIGIT_MAX - 1; i++) {
        int d = digits[i];
        int n = digits[i + 1];
        assert(d < 10);
        assert(n < 10);
        // 未確定から未確定
        if (n == 0) {
            rep(ti, t + 1) {
                dp[i + 1][false][n][ti] += dp[i][false][d][ti];
            }
        } else {
            rep(ti, t) {
                dp[i + 1][false][n][ti + 1] += dp[i][false][d][ti];
            }
        }

        // 未確定から確定
        for (int jp = 0; jp < 10; jp++) {
            for (int jn = 0; jn < 10; jn++) {
                assert(jn < 10);
                assert(jn >= 0);
                if (jn >= n) continue;

                if (jn == 0) {
                    rep(ti, t + 1) {
                        dp[i + 1][true][jn][ti] += dp[i][false][jp][ti];
                    }
                } else {
                    rep(ti, t) {
                        dp[i + 1][true][jn][ti + 1] += dp[i][false][jp][ti];
                    }
                }

                // dp[i + 1][true][jn] += dp[i][false][jp];など
            }
        }
        // 確定から確定
        for (int jp = 0; jp < 10; jp++) {
            for (int jn = 0; jn < 10; jn++) {
                if (jn == 0) {
                    rep(ti, t + 1) {
                        dp[i + 1][true][jn][ti] += dp[i][true][jp][ti];
                    }
                } else {
                    rep(ti, t) {
                        dp[i + 1][true][jn][ti + 1] += dp[i][true][jp][ti];
                    }
                }
            }
        }

        // この桁が初めての0以外の数字の場合
        for (int j = 1; j < 10; j++) {
            dp[i + 1][true][j][1] += 1;
        }
    }

    ll sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += dp[DIGIT_MAX - 1][true][i][t];
    }
    for (int i = 0; i < 10; i++) {
        sum += dp[DIGIT_MAX - 1][false][i][t];
    }

    return sum;
}

int main() {
    string s;
    int k;
    cin >> s >> k;

    cout << digit_dp(s, k) << endl;

}

