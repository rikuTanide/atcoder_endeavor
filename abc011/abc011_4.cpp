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

class Pascal {
    vector<vector<double >> dp;

public:
    Pascal() {
        dp.resize(2000);
        dp[0].push_back(1);

        for (int i = 1; i < 2000; i++) {
            dp[i].resize(i + 1);
            for (int j = 0; j <= dp[i - 1].size(); j++) {
                dp[i][j] = get(i - 1, j - 1) / 2 + get(i - 1, j) / 2;
            }
        }
    }

    double get(int i, int j) {
        if (j == -1) return 0;
        if (j == dp[i].size()) return 0;
        return dp[i][j];
    }

};

int main() {

    Pascal pascal;


    int n;
    ll d, x, y;
    cin >> n >> d >> x >> y;

    if (x % d != 0) {
        cout << 0 << endl;
        ret();
    }
    if (y % d != 0) {
        cout << 0 << endl;
        ret();
    }


    auto can = [&](ll jump_count, ll goal) -> bool {
        if (jump_count == 0 && goal != 0) return false;
        ll min_jump_count = abs(goal) / d;
        if (jump_count < min_jump_count) return false;
        ll surplus_jump_count = jump_count - min_jump_count;
        if (surplus_jump_count % 2 != 0) return false;
        return true;
    };

    double ans = 0;

    auto rate = [&](ll jump_count, ll goal) -> double {
        ll min_jump_count = abs(goal) / d;
        ll surplus_jump_count = jump_count - min_jump_count;
        ll a = min_jump_count + (surplus_jump_count / 2);

        double ans = pascal.get(jump_count, a);
        return ans;
    };

    for (int i = 0; i <= n; i++) {
        ll vertical = i;
        ll horizontal = n - i;

        if (!can(vertical, y)) continue;
        if (!can(horizontal, x)) continue;

        double vertical_rate = rate(vertical, y);
        double horizontal_rate = rate(horizontal, x);

        double par = pascal.get(n, i);

        double now = horizontal_rate * vertical_rate * par;

        ans += now;
    }

    cout << setprecision(20) << ans << endl;

}
