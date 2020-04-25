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

bool is49(int i) {
    return i == 4 || i == 9;
}

ll digit_dp(ll k) {
    if(k == 0) return 0;
    const int DIGIT_MAX = 30;
    vector<vector<vector<vector<ll>>>> dp(DIGIT_MAX,
                                          vector<vector<vector<ll>>>(2, vector<vector<ll>>(10, vector<ll>(10, 0))));
    vector<ll> digits(DIGIT_MAX);
    {
        int i = 0;
        while (k > 0) {
            ll m = k % 10;
            digits[i] = m;
            k /= 10;
            i++;
        }
        reverse(digits.begin(), digits.end());
    }

    int first_i = 0, first_j = 0;
    rep(i, DIGIT_MAX) {
        if (digits[i] == 0) continue;
        first_i = i;
        first_j = digits[i];
        break;
    }
    rep(i, 10) {
        if (i == 0) continue;
        if (i < first_j) dp[first_i][true][is49(i)][i] = 1;
    }
    dp[first_i][false][is49(first_j)][first_j] = 1;

    // Kより小さいことが......

    for (int i = first_i; i < DIGIT_MAX - 1; i++) {
        int d = digits[i];
        int n = digits[i + 1];
        assert(d < 10);
        assert(n < 10);
        // 未確定から未確定
        assert(dp[i][false][true][d] + dp[i][false][false][d] == 1);
        if (dp[i][false][true][d] == 1) {
            dp[i + 1][false][true][n] += 1;
        } else if (is49(n)) {
            dp[i + 1][false][true][n] += 1;
        } else {
            dp[i + 1][false][false][n] += 1;
        }

        // 未確定から確定
        for (int jp = 0; jp < 10; jp++) {
            for (int jn = 0; jn < 10; jn++) {
                assert(jn < 10);
                assert(jn >= 0);
                if (jn >= n) continue;
                if (is49(jn)) {
                    dp[i + 1][true][true][jn] += dp[i][false][true][jp];
                    dp[i + 1][true][true][jn] += dp[i][false][false][jp];
                } else {
                    dp[i + 1][true][true][jn] += dp[i][false][true][jp];
                    dp[i + 1][true][false][jn] += dp[i][false][false][jp];
                }
            }
        }
        // 確定から確定
        for (int jp = 0; jp < 10; jp++) {
            for (int jn = 0; jn < 10; jn++) {
                if (is49(jn)) {
                    dp[i + 1][true][true][jn] += dp[i][true][true][jp];
                    dp[i + 1][true][true][jn] += dp[i][true][false][jp];
                } else {
                    dp[i + 1][true][true][jn] += dp[i][true][true][jp];
                    dp[i + 1][true][false][jn] += dp[i][true][false][jp];
                }
            }
        }

        // この桁が初めての0以外の数字の場合
        for (int j = 1; j < 10; j++) {
            dp[i + 1][true][is49(j)][j] += 1;
        }
    }

    ll sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += dp[DIGIT_MAX - 1][true][true][i];
    }
    for (int i = 0; i < 10; i++) {
        sum += dp[DIGIT_MAX - 1][false][true][i];
    }

    return sum;
}


int main() {
    ll a, b;
    cin >> a >> b;
    a--;
    cout << digit_dp(b) - digit_dp(a) << endl;

}

