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

const int mod = 1000000007;

struct Monster {
    int place;
    ll hit_point;
};

struct Bom {
    int place;
    ll count;
};

int main() {
    int n, d, a;
    cin >> n >> d >> a;

    vector<Monster> monsters(n);
    rep(i, n) cin >> monsters[i].place >> monsters[i].hit_point;
    sort(monsters.begin(), monsters.end(), [](Monster ma, Monster mb) { return ma.place < mb.place; });

    vector<ll> places(n);
    rep(i, n) places[i] = monsters[i].place;

    vector<ll> dp(n, 0);
    ll ans = 0;
    rep(i, n) {
        if (i != 0) dp[i] += dp[i - 1];
        ll point = a * dp[i];
        if (monsters[i].hit_point <= point) continue;
        ll nokori = monsters[i].hit_point - point;

        ll count = (nokori + a - 1) / a;
        ans += count;
        dp[i] += count;
        auto it = lower_bound(places.begin(), places.end(), monsters[i].place + (2 * d) + 1);
        if (it == places.end()) continue;
        int index = distance(places.begin(), it);
        dp[index] -= count;
    }
    cout << ans << endl;
}

