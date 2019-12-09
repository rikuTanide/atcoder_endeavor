#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = 10e15;
const ll MINF = -10e10;
//const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);



int main() {
    ll n;
    cin >> n;

    vector<P> xs(n);

    rep(i, n) {
        int x;
        cin >> x;
        P p(x, i);
        xs[i] = p;
    }
    sort(xs.begin(), xs.end());

    ll cli = (n - 1) / 2;
    ll cl = xs[cli].first;
    ll rli = n - 1 - ((n - 1) / 2);
    ll cr = xs[rli].first;


    vector<P> ans(n);

    for (ll i = 0; i < (n / 2); i++) {
        P p = xs[i];
        P a(p.second, cr);
        ans[i] = a;
    }
    for (ll i = (n / 2); i < n; i++) {
        P p = xs[i];
        P a(p.second, cl);
        ans[i] = a;
    }

    sort(ans.begin(), ans.end());

    for (P p : ans) {
        cout << p.second << endl;
    }

}
