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

int get_time() {
    int a, b;
    scanf("%d:%d", &a, &b);
    return a * 100 + b;
}

int main() {
    int n;
    cin >> n;

    vector<int> starts(n), ends(n);
    rep(i, n) starts[i] = get_time(), ends[i] = get_time();

    vector<int> dp(1 << n, n);
    for (int i = 1; i < (1 << n); i = (i << 1)) {
        dp[i] = 1;
    }


    auto can_one = [&](int i) -> bool {
        vector<int> v;
        rep(j, n) if ((i >> j) & 1) v.push_back(j);

        for (int x = 0; x < v.size(); x++) {
            for (int y = x + 1; y < v.size(); y++) {
                int s1 = starts[v[x]], e1 = ends[v[x]];
                int s2 = starts[v[y]], e2 = ends[v[y]];

                if (s2 < s1) swap(s1, s2), swap(e1, e2);

                if (s2 < e1) return false;

                if (e2 >= 2400) {
                    e2 -= 2400;
                    if (s1 < e2) return false;
                }

            }
        }
        return true;
    };


    auto get_min = [&](int i) -> int {
        int ans = n;
        for (int s = (i - 1) & i; s > 0; s = (s - 1) & i) {
            int t = i ^s;
            int now = dp[s] + dp[t];
            cmin(ans, now);
        }
        return ans;
    };

    rep(i, 1 << n) {
        if (__builtin_popcount(i) == 1) continue;
        if (can_one(i)) dp[i] = 1;
        else dp[i] = get_min(i);
    }

    cout << dp[(1 << n) - 1] << endl;

}
