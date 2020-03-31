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

ll lager(vector<ll> &v, ll target) {
    return distance(upper_bound(v.begin(), v.end(), target), v.end());
}

ll check(vector<ll> &xys, vector<ll> &cs, ll target) {
    ll sum = 0;
    for (ll c : cs) {
        if (c >= target) {
            sum += xys.size();
            continue;
        }
        ll i_target = target - c;
        ll l = lager(xys, i_target);
        sum += l;
    }
    return sum;
}

ll solve(vector<ll> &xys, vector<ll> &cs, ll i, ll all_sum) {

    ll floor = 0;
    ll ceil = all_sum;

    while (floor + 1 < ceil) {
        ll mid = (floor + ceil) / 2;
        ll count = check(xys, cs, mid);
        bool b = i < count;
        if (b) {
            floor = mid;
        } else {
            ceil = mid;
        }
    }
    return ceil;
}

int main() {
    ll x, y, z, k;
    cin >> x >> y >> z >> k;

    vector<ll> as(x), bs(y), cs(z);
    rep(i, x) cin >> as[i];
    rep(i, y) cin >> bs[i];
    rep(i, z) cin >> cs[i];

    ll all_sum = *max_element(as.begin(), as.end())
                 + *max_element(bs.begin(), bs.end())
                 + *max_element(cs.begin(), cs.end()) + 100;

    vector<ll> xys;
    for (ll a : as) {
        for (ll b : bs) {
            xys.push_back(a + b);
        }
    }
    sort(xys.begin(), xys.end());
    sort(cs.begin(), cs.end());

    rep(i, k) {
        cout << solve(xys, cs, i, all_sum) << endl;
    }
}
