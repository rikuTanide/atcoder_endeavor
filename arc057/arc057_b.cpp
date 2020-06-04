#include <bits/stdc++.h>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<double, ll> P;
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

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//const ll mod = 1e10;
typedef priority_queue<string, vector<string>, greater<string> > PQ_ASK;

class CumulativeSum {
    vector<ll> numbers;
    vector<ll> sums;

public:
    CumulativeSum(int n) {
        numbers.resize(n);
        sums.resize(n);
    }

    void set(int i, ll value) {
        numbers[i] = value;
    }

    ll getSum(int i) {
        if (i == -1) return 0;
        if (i == sums.size()) return sums.back();
        return sums[i];
    }

    ll getSectionSum(int start, int end) {
        return getSum(end) - getSum(start - 1);
    }

    void build() {
        for (int i = 0; i < numbers.size(); i++) {
            sums[i] = getSum(i - 1) + numbers[i];
        }
    }

};

int main() {
    int n, k;
    cin >> n >> k;

    vector<ll> v(n);
    rep(i, n) cin >> v[i];

    {
        ll sum = accumulate(v.begin(), v.end(), 0ll);
        if (sum == k) {
            cout << 1 << endl;
            ret();
        }
    }

    CumulativeSum cs(n);
    rep(i, n) cs.set(i, v[i]);
    cs.build();

    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, INF));
    dp[0][0] = 0;

    auto get_prev_rate = [&](int i, int j) -> double {
        if (i == 0) return 0;
        double sum = cs.getSum(i - 1);
        double win = dp[i][j];

        return win / sum;
    };

    rep(i, n) {
        rep(j, n) {
            if (dp[i][j] == INF) continue;
            cmin(dp[i + 1][j], dp[i][j]); // 全敗
            double prev_rate = get_prev_rate(i, j);
            ll next_win = (v[i] * prev_rate) + 1;
            if (next_win > v[i]) continue;
            ll next = dp[i][j] + next_win;

            cmin(dp[i + 1][j + 1], next);
        }
    }
    int ans = 0;
    rep(i, n) {
        if (dp.back()[i] > k) continue;
        ans = i;
    }

    cout << ans << endl;

}
