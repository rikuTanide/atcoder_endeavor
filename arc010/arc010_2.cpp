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

int main() {
    int n;
    cin >> n;
    set<P> holidays;
    rep(i, n) {
        int m, d;
        scanf("%d/%d", &m, &d);

        holidays.insert({m, d});
    }

    vector<int> month_days = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    vector<P> days;
    for (int i = 1; i <= 12; i++) {
        for (int j = 1; j <= month_days[i - 1]; j++) {
            days.push_back(P(i, j));
        }
    }

    vector<bool> is_holiday(366, false);
    rep(i, 366) {
        is_holiday[i] = i % 7 == 0 || i % 7 == 6;
    }

    int q = 0;
    rep(i, 366) {
        P day = days[i];
        if (holidays.find(day) != holidays.end()) {
            // 祝日
            if (is_holiday[i]) {
                q++;
            } else {
                is_holiday[i] = true;
            }
        } else {
            if (is_holiday[i]) {

            } else if (q > 0) {
                q--;
                is_holiday[i] = true;
            } else {

            }
        }
    }

    vector<int> dp(366, -1);
    dp[0] = 1;
    rep(i, 366) {
        if (i == 0) continue;
        if (is_holiday[i]) dp[i] = dp[i - 1] + 1;
        else dp[i] = 0;
    }

    int ans = *max_element(dp.begin(), dp.end());
    cout << ans << endl;

}
