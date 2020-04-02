#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
using namespace std;
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

#include <iostream>
#include <vector>

using namespace std;


int main() {
    int n, k;
    cin >> n >> k;

    vector<P> ans;
    rep(i, n) {
        if (i == 0) continue;
        ans.emplace_back(0, i);
    }

    vector<P> bridge;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            bridge.emplace_back(i, j);
        }
    }

    assert(bridge.size() == (n - 1) * (n - 2) / 2);
    rep(i, (n - 1) * (n - 2) / 2 - k) {
        ans.push_back(bridge[i]);
    }

    if ((n - 1) * (n - 2) / 2 < k) {
        cout << -1 << endl;
        ret();
    }

    cout << ans.size() << endl;
    for (P p : ans) printf("%lld %lld\n", p.first + 1, p.second + 1);

}
