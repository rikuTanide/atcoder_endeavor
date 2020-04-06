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

bool can_choose(ll n, ll m, ll v, ll p, vector<ll> &problems, ll border) {
    // borderを当選させたい。可能か？
    if (border < p) return true;
    ll target = problems[p - 1];
    if (problems[border] + m < target) return false;

    ll budget = v * m;
    // border問目に全員が投票
    // P-1問目までは全員が投票
    // p問目からborder問目まではborder問目と一致するように投票
    // border+1問目移行は全部上げる
    // 票が余ったらfalse

    auto allocate = [&](ll ma) {
        ll k = min({budget, m, ma});
        budget -= k;
        return k;
    };

    ll border_point = problems[border] + allocate(INF);
    rep(i, p - 1) allocate(INF);

    for (ll i = border + 1; i < n; i++) allocate(INF);

    auto allocate_for_border_point = [&](ll i) {
        ll from = problems[i];
        assert(border_point >= from);
        ll diff = border_point - from;
        allocate(diff);
    };

    for (ll i = p; i < border; i++) allocate_for_border_point(i);

    return budget == 0;
}


int main() {
    ll n, m, v, p;
    cin >> n >> m >> v >> p;


    vector<ll> problems(n);
    rep(i, n) cin >> problems[i];
    sort(problems.rbegin(), problems.rend());
    ll floor = 0, ceil = n - 1;
    if (can_choose(n, m, v, p, problems, ceil)) {
        cout << n << endl;
        ret();
    }
    while (floor + 1 < ceil) {
        ll mid = (floor + ceil) / 2;
        bool b = can_choose(n, m, v, p, problems, mid);
        if (b) {
            floor = mid;
        } else {
            ceil = mid;
        }
    }
    assert(can_choose(n, m, v, p, problems, floor));
    assert(!can_choose(n, m, v, p, problems, ceil));
    cout << floor + 1 << endl;
}
