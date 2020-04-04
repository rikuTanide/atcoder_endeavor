#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

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

#include <iostream>
#include <vector>

using namespace std;

set<int> get_run_run(int n) {
    set<int> res;
    res.insert(n);
    res.insert(n + 1);
    res.insert(n - 1);
    res.erase(-1);
    res.erase(10);
    return res;
}

bool is_run_run(int i, int j) {
    return abs(i - j) <= 1;
}

ll count_run_run(ll k) {
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

    for (int i = first_i; i < DIGIT_MAX - 1; i++) {
        int d = digits[i];
        int n = digits[i + 1];
        assert(d < 10);
        assert(n < 10);
        // 未確定から未確定
        if (is_run_run(d, n)) {
            dp[i + 1][false][n] += dp[i][false][d];
        }
        // 未確定から確定
        for (int jp = 0; jp < 10; jp++) {
            for (int jn : get_run_run(jp)) {
                assert(jn < 10);
                assert(jn >= 0);
                if (jn >= n) continue;
                dp[i + 1][true][jn] += dp[i][false][jp];
            }
        }
        // 確定から確定
        for (int jp = 0; jp < 10; jp++) {
            for (int jn : get_run_run(jp)) {
                assert(jn < 10);
                assert(jn >= 0);
                dp[i + 1][true][jn] += dp[i][true][jp];
            }
        }

        // 初めての桁
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

    return sum;
}

int main() {

    ll k;
    cin >> k;

    if (k < 10) {
        cout << k << endl;
        ret();
    }

    ll floor = 0;
    ll ceil = INF;

    while (floor + 1 < ceil) {
        ll mid = (floor + ceil) / 2;
        bool b = count_run_run(mid) < k;
        if (b) {
            floor = mid;
        } else {
            ceil = mid;
        }
    }

    cout << ceil << endl;
}

