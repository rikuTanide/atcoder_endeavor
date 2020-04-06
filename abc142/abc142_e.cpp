#include <bits/stdc++.h>
#include <cmath>

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

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
const int mod = 1000000007;
//const ll mod = 1e10;
typedef priority_queue<string, vector<string>, greater<string> > PQ_ASK;

#include <iostream>
#include <vector>

using namespace std;

struct Key {
    ll match, price;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Key> keys(m);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        ll k = 0;
        rep(j, b) {
            int c;
            cin >> c;
            c--;
            k += (1ll << c);
        }
        keys[i].match = k;
        keys[i].price = a;
    }

    vector<ll> dp(1LL << n, -1);
    dp[0] = 0;
    for (Key key : keys) {
        for (ll i = 0; i < (1LL << n); i++) {
            if (dp[i] == -1) continue;
            ll next = i | key.match;
            if (dp[next] == -1) dp[next] = dp[i] + key.price;
            else dp[next] = min(dp[next], dp[i] + key.price);
        }
    }
    cout << dp[(1LL << n) - 1] << endl;
}