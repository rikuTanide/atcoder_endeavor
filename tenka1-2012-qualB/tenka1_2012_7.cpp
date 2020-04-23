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

int get_minute() {
    char a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    assert(c == ':');
    int hour = (a - '0') * 10 + (b - '0');
    int minute = (d - '0') * 10 + (e - '0');

    int minutes = hour * 60 + minute;
    return minutes;
}

int main() {
    int n;
    cin >> n;
    vector<int> starts(n), ends(n);

    rep(i, n) {
        starts[i] = get_minute();
        ends[i] = get_minute();
    }

    auto can_one = [&](int i) {
        vector<int> s, e;
        rep(j, n) {
            if (!((i >> j) & 1))continue;
            s.push_back(starts[j]);
            e.push_back(ends[j]);
        }

        for (int j = 0; j < s.size(); j++) {
            for (int k = j + 1; k < s.size(); k++) {
                int s1 = s[j], e1 = e[j], s2 = s[k], e2 = e[k];
                if (s1 > s2) {
                    swap(s1, s2);
                    swap(e1, e2);
                }
                assert(s1 <= s2);
                if (s2 < e1) return false;
                if (s1 + (24 * 60) < e2) return false;
            }
        }
        return true;
    };

    vector<int> dp(1 << n, n);
    dp[0] = 0;
    for (int i = 1; i < (1 << n); i = i << 1) {
        dp[i] = 1;
    }

    auto min_chair = [&](int i) {

        vector<int> u;
        rep(j, n) if ((i >> j) & 1) u.push_back(j);
        int ans = n;
        for (int s = (i - 1) & i; s > 0; s = (s - 1) & i) {
            int t = i ^s;
            int now = dp[s] + dp[t];
            cmin(ans, now);
        }
        return ans;
    };


    rep(i, 1 << n) {
        if (__builtin_popcount(i) <= 1) continue;
        if (can_one(i)) dp[i] = 1;
        else dp[i] = min_chair(i);
    }

    cout << dp[(1 << n) - 1] << endl;

}
