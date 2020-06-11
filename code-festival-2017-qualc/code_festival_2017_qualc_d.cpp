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
    string s;
    cin >> s;
    int n = s.size();

    vector<int> hs(n, 0);

    rep(i, n) {
        if (i == 0) {
            char c = s[i];
            int j = c - 'a';
            int next = 1 << j;
            hs[0] = next;
        } else {
            char c = s[i];
            int j = c - 'a';
            int next = hs[i - 1] ^(1 << j);
            hs[i] = next;
        }
    }


    vector<int> dp(n, -1);

    map<int, int> cache;
    cache[0] = -1;
    rep(i, n) if (cache.find(hs[i]) == cache.end()) cache[hs[i]] = i;


    auto set = [&](int i, int k) {
        if (dp[i] == -1) dp[i] = k;
        else
            cmin(dp[i], k);
    };


    auto get = [&](int i) {
        if (i == -1) return 0;
        return dp[i];
    };

    for (int i = 0; i < n; i++) {

        {
            dp[i] = get(i - 1) + 1;
            int current = hs[i];

            int j = cache[current];
            set(i, get(j) + 1);
        }

        rep(a, 26) {
            int current = (1 << a) ^hs[i];
            if (cache.find(current) == cache.end() || cache[current] >= i) continue;
            int j = cache[current];
            set(i, get(j) + 1);
        }

        if (dp[i] < dp[cache[hs[i]]]) {
            cache[hs[i]] = i;
        }

    }

    cout << dp[n - 1] << endl;

}
