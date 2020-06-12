#include <bits/stdc++.h>

const double PI = 3.14159265358979323846;
using namespace std;
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

bool contain(set<char> &s, char a) { return s.find(a) != s.end(); }

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//const ll mod = 1e10;
typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;


int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    rep(i, n) cin >> v[i];

    ll all = accumulate(v.begin(), v.end(), 0ll);

    vector<bool> dp(all + 1, false);
    dp[0] = true;


    rep(i, n) {


        vector<bool> next(all + 1, false);

        auto ok = [&](int i, int j) {
            if (j > all) return;
            next[j] = true;
        };

        rep(j, all + 1) {
            if (!dp[j]) continue;
            ll next = j + v[i];
            ok(i + 1, next);
            ok(i + 1, j);
        }

        dp = next;

    }

    for (ll i = (all + 1) / 2; i <= all; i++) {
        if (dp[i]) {
            cout << i << endl;
            ret();
        }
    }

}