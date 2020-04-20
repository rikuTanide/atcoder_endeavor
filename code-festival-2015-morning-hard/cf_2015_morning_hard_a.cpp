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

typedef pair<string, string> PS;

int main() {
    int n;
    cin >> n;
    vector<ll> lens(n);
    rep(i, n) cin >> lens[i];

    vector<ll> len_sum(n + 1);
    rep(i, n) len_sum[i + 1] = len_sum[i] + lens[i];
    vector<ll> len_sum_r(n + 1);
    rep(i, n) len_sum_r[i + 1] = len_sum_r[i] + i * lens[i];

    ll ans = INF;
    rep(i, n) {
        if (i % 2 == 1) continue;
        ll lad = i;
        ll rad = (n - 1 - i);
        lad = lad * (lad - 1) / 2;
        rad = rad * (rad - 1) / 2;

        ll ltot = i * len_sum[i] - len_sum_r[i];
        ll rtot = len_sum_r[n] - len_sum_r[i + 1] - i * (len_sum[n] - len_sum[i + 1]);
        ans = min(ans, lad + rad + ltot + rtot);
    }
    cout << ans << endl;

}
