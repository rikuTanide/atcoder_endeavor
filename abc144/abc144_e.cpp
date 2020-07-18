#include <bits/stdc++.h>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

std::istream &operator>>(std::istream &in, set<ll> &o) {
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
//typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;

int main() {
    int n, k;
    cin >> n >> k;

    vector<ll> costs(n), foods(n);
    rep(i, n) cin >> costs[i];
    rep(i, n) cin >> foods[i];

    sort(costs.begin(), costs.end());
    sort(foods.rbegin(), foods.rend());

    auto check = [&](ll x) -> bool {
        ll ans = 0;
        rep(i, n) {
            ll c = costs[i];
            ll f = foods[i];
            if (c * f <= x) continue;
            ll border = x / f;
            assert(border < c);
            ll t = c - border;
            ans += t;
        }
        return ans <= k;
    };


    ll floor = 0, ceil = INF;

    if (check(floor)) {
        cout << 0 << endl;
        ret();
    }

    assert(!check(ceil));
    
    while (floor + 1 < ceil) {
        ll mid = (floor + ceil) / 2;
        bool ok = check(mid);
        if (ok) ceil = mid;
        else floor = mid;
    }

    cout << ceil << endl;

}