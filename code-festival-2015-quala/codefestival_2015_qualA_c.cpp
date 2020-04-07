#define _GLIBCXX_DEBUG

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


struct HomeWork {
    ll l, s;
};

int main() {
    ll n, t;
    cin >> n >> t;

    vector<HomeWork> homeworks(n);
    rep(i, n)cin >> homeworks[i].l >> homeworks[i].s;

    ll sum = 0;
    rep(i, n) sum += homeworks[i].l;

    if (sum <= t) {
        cout << 0 << endl;
        ret();
    }

    priority_queue<ll> diff;
    rep(i, n) diff.push(homeworks[i].l - homeworks[i].s);

    int ans = 0;
    while (!diff.empty() && t < sum) {
        ans++;
        sum -= diff.top();
        diff.pop();
    }
    if (diff.empty() && t < sum) {
        cout << -1 << endl;
        ret();
    }
    cout << ans << endl;

}
