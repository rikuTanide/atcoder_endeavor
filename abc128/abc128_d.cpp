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
    ll n, k;
    cin >> n >> k;
    vector<ll> jewelries(n);
    rep(i, n) cin >> jewelries[i];

    deque<ll> dq;
    rep(i, n) dq.push_back(jewelries[i]);

    auto check = [&](ll l, ll r, ll m) {
        deque<ll> dq_tmp = dq;
        ll sum = 0;
        PQ_ASK pqAsk;
        rep(i, l) {
            assert(!dq_tmp.empty());
            ll f = dq_tmp.front();
            sum += f;
            pqAsk.push(f);
            dq_tmp.pop_front();
        }

        rep(i, r) {
            assert(!dq_tmp.empty());
            ll b = dq_tmp.back();
            sum += b;
            pqAsk.push(b);
            dq_tmp.pop_back();
        }

        rep(i, m) {
            ll f = pqAsk.top();
            sum -= f;
            pqAsk.pop();
        }
        return sum;
    };
    ll ans = 0;
    rep(i, k + 1) {
        rep(j, min(i + 1, n + 1)) {
            ll m = i - j;
            if (m > j) continue;
            rep(l, j + 1) {
                ll r = j - l;
                ll now = check(l, r, m);
                cmax(ans, now);
            }
        }
    }
    cout << ans << endl;
}
