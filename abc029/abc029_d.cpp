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

vector<vector<vector<ll>>> digit_dp_all(ll k) {
    const int DIGIT_MAX = 30;
    vector<vector<vector<ll>>> dp(DIGIT_MAX, vector<vector<ll>>(2, vector<ll>(10, 0)));
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
        if (i < first_j) dp[first_i][true][i] = 1;
    }
    dp[first_i][false][first_j] = 1;

    // Kより小さいことが......

    for (int i = first_i; i < DIGIT_MAX - 1; i++) {
        int d = digits[i];
        int n = digits[i + 1];
        assert(d < 10);
        assert(n < 10);
        // 未確定から未確定
        dp[i + 1][false][n] = 1;

        // 未確定から確定
        for (int jn = 0; jn < 10; jn++) {
            if (jn >= n) continue;
            dp[i + 1][true][jn] += dp[i][false][d];
        }

        // 確定から確定
        for (int jp = 0; jp < 10; jp++) {
            for (int jn = 0; jn < 10; jn++) {
                dp[i + 1][true][jn] += dp[i][true][jp];
            }
        }

        for (int j = 1; j < 10; j++) {
            dp[i + 1][true][j] += 1;
        }
    }

    ll sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += dp[DIGIT_MAX - 1][true][i];
    }
    for (int i = 0; i < 10; i++) {
        sum += dp[DIGIT_MAX - 1][false][i];
    }

    return dp;
}


ll digit_dp(ll k) {

    vector<vector<vector<ll>>> flow = digit_dp_all(k);

    const int DIGIT_MAX = 30;
    vector<vector<vector<ll>>> dp(DIGIT_MAX, vector<vector<ll>>(2, vector<ll>(10, 0)));
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
    dp[first_i][first_j > 1][1] = 1;

    // Kより小さいことが......

    for (int i = first_i; i < DIGIT_MAX - 1; i++) {
        int d = digits[i];
        int n = digits[i + 1];
        assert(d < 10);
        assert(n < 10);
        // 未確定から未確定
        dp[i + 1][false][n] += dp[i][false][d];
        if (n == 1) dp[i + 1][false][n]++;

        // 未確定から確定
        for (int jn = 0; jn < 10; jn++) {
            if (jn >= n) continue;
            dp[i + 1][true][jn] += dp[i][false][d];
            if (jn == 1) dp[i + 1][true][jn]++;
        }

        // 確定から確定
        for (int jp = 0; jp < 10; jp++) {
            for (int jn = 0; jn < 10; jn++) {
                dp[i + 1][true][jn] += dp[i][true][jp];
            }
            dp[i + 1][true][1] += flow[i][true][jp];
        }


        dp[i + 1][true][1]++;
    }

    ll sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += dp[DIGIT_MAX - 1][true][i];
    }
    for (int i = 0; i < 10; i++) {
        sum += dp[DIGIT_MAX - 1][false][i];
    }

    return sum;
}

int main() {
    ll n;
    cin >> n;

    cout << digit_dp(n) << endl;
}
