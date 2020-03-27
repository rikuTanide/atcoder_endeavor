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

//const ll mod = 1e10;
typedef priority_queue<string, vector<string>, greater<string> > PQ_ASK;

#include <iostream>
#include <vector>

using namespace std;

const int mod = 1000000007;


int main() {
    int a, b, q;
    cin >> a >> b >> q;

    vector<ll> shrine(a), temples(b);
    rep(i, a) cin >> shrine[i];
    rep(i, b) cin >> temples[i];

    auto f = [](vector<ll> &v, ll x) {
        P p;
        auto it = lower_bound(v.begin(), v.end(), x);
        if (it == v.end()) {
            it--;
            p.first = x - *it;
            p.second = INF;
            return p;
        }
        if (it == v.begin()) {
            p.first = INF;
            p.second = *it - x;
            return p;
        }
        p.second = *it - x;
        it--;
        p.first = x - *it;
        return p;
    };

    rep(i, q) {
        ll x;
        cin >> x;
        P s = f(shrine, x);
        P t = f(temples, x);
        assert(s.first >= 0);
        assert(s.second >= 0);
        assert(t.first >= 0);
        assert(t.second >= 0);

        ll ans = INF;
        cmin(ans, max(s.second, t.second));
        cmin(ans, max(s.first, t.first));
        cmin(ans, min(s.first, t.second) * 2 + max(s.first, t.second));
        cmin(ans, min(s.second, t.first) * 2 + max(s.second, t.first));

        cout << ans << endl;
    }

}
