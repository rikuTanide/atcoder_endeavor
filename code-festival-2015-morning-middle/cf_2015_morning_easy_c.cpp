//#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
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


int main() {
    int test_count;
    ll use_performance, max_performance, border_line;
    cin >> test_count >> use_performance >> max_performance >> border_line;

    vector<ll> points(test_count - 1);
    rep(i, test_count - 1) cin >> points[i];

    sort(points.rbegin(), points.rend());

    ll need_points = use_performance * border_line;

    if (accumulate(points.begin(), points.begin() + use_performance, 0ll) >= need_points) {
        cout << 0 << endl;
        ret();
    }

    ll still = accumulate(points.begin(), points.begin() + use_performance - 1, 0ll);
    ll ans = need_points - still;
    if (ans > max_performance) {
        cout << -1 << endl;
        ret();
    }
    cout << ans << endl;

}
