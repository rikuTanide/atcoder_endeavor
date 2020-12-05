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

int search(vector<int> &dp, int x) {
    auto begin = dp.begin();
    auto end = dp.end();

    auto er = equal_range(begin, end, x);
    int eq = distance(er.first, er.second);
    int sm = distance(begin, lower_bound(begin, end, x));
    return eq + sm;
}

int main() {
    int n;
    cin >> n;

    vector<int> cards(n);
    rep(i, n) cin >> cards[i];
    assert(n <= 1000);

    vector<int> dp(n + 1, INT_MAX);
    dp[0] = INT_MIN;

    rep(i, n) {
        int k = cards[i];
        int index = search(dp, k);
        cmin(dp[index], k);
    }
    int now = 0;
    rep(i, n + 1) {
        int k = dp[i];
        if (k == INT_MIN || k == INT_MAX) continue;
        now = i;
    }
    cout << n - now << endl;
}

