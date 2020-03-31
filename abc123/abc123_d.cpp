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
    ll x, y, z, k;
    cin >> x >> y >> z >> k;

    vector<ll> as(x), bs(y), cs(z);
    rep(i, x) cin >> as[i];
    rep(i, y) cin >> bs[i];
    rep(i, z) cin >> cs[i];


    vector<ll> xys;
    for (ll a : as) {
        for (ll b : bs) {
            xys.push_back(a + b);
        }
    }
    sort(xys.rbegin(), xys.rend());
    sort(cs.rbegin(), cs.rend());

    vector<ll> use_xys;
    rep(i, min((ll) k, (ll) xys.size())) {
        use_xys.push_back(xys[i]);
    }

    vector<ll> ans;
    for (ll ab : use_xys) {
        for (ll c : cs) {
            ans.push_back(ab + c);
        }
    }

    sort(ans.rbegin(), ans.rend());

    rep(i, k) {
        cout << ans[i] << endl;
    }
}
