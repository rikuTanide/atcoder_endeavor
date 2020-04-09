#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
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

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    x--;
    y--;

    vector<ll> from_xs(n, INF), from_ys(n, INF);
    {
        from_xs[x] = 0;
        from_xs[y] = 1;
        rep(i, n) {
            if (i == 0) continue;
            cmin(from_xs[i], from_xs[i - 1] + 1);
        }
        rep(i, n) {
            if (i == 0) continue;
            ll j = n - 1 - i;
            cmin(from_xs[j], from_xs[j + 1] + 1);
        }
    }
    {
        from_ys[x] = 1;
        from_ys[y] = 0;
        rep(i, n) {
            if (i == 0) continue;
            cmin(from_ys[i], from_ys[i - 1] + 1);
        }
        rep(i, n) {
            if (i == 0) continue;
            ll j = n - 1 - i;
            cmin(from_ys[j], from_ys[j + 1] + 1);
        }
    }


    vector<ll> ans(n - 1);

    rep(i, n) {
        rep(j, n) {
            if (i <= j) continue;
            ll direct = abs(i - j);
            ll via_x = from_xs[i] + from_xs[j];
            ll via_y = from_ys[i] + from_ys[j];

            ll now = min({direct, via_x, via_y});
            ans[now - 1]++;
        }
    }
    for (ll a : ans) cout << a << endl;
}
