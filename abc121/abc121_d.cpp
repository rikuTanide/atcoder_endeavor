#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
//using namespace boost::multiprecision;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
const ll INF = 1e15;
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
const int mod = 1000000007;
//const ll mod = 1e10;
typedef priority_queue<string, vector<string>, greater<string> > PQ_ASK;

vector<ll> check(ll a) {
    vector<ll> ans(60);
    for (int i = 0; i < 60; i++) {
        ll cycle = 1ll << (i + 1);
        ll cycle_count = (a + 1) / cycle;
        ll under = cycle_count * cycle;

        ll cycle_one_count = cycle_count * (cycle / 2);
        ll over = (a + 1) - under;
        ll last_one_count = max(over - (cycle / 2), 0ll);
        ll now = cycle_one_count + last_one_count;
        ans[i] = now;
    }
    return ans;
}

int main() {

    ll a, b;
    cin >> a >> b;

    vector<ll> ac = check(max(a - 1, 0ll));
    vector<ll> bc = check(b);

    vector<ll> bits(60);
    rep(i, 60) bits[i] = bc[i] - ac[i];

    ll ans = 0;
    rep(i, 60) {
        ll now = bits[i] % 2;
        ll d = now << i;
        ans += d;
    }
    cout << ans << endl;

}