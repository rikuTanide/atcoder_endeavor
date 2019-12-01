#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = 10e10;
const ll MINF = -10e10;
//const int INF = INT_MAX;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)

typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;
const int mod = 1000000007;
//ifstream myfile("C:\\Users\\riku\\Downloads\\01.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;

int comp(ll i, ll j) {
    if (i > j) {
        return -1;
    } else if (i == j) {
        return 1;
    } else {
        return 1;
    }
}


int main() {
    int n;
    cin >> n;

    vector<ll> as(n);
    rep(i, n) cin >> as[i];

    ll max_a = -1;
    ll min_a = INF;
    rep(i, n) max_a = max(max_a, as[i]);
    rep(i, n) min_a = min(min_a, as[i]);

    vector<ll> u_or_d(n);
    vector<ll> ruisekiwa(n + 1);

    ll cell = max_a + 1;
    ll floor = min_a;
    while (floor + 1 < cell) {
        ll mid = (cell + floor) / 2;

        rep(j, n) u_or_d[j] = comp(mid, as[j]);

        ruisekiwa[0] = 0;
        for (int i = 0; i <= n; i++) {
            ruisekiwa[i + 1] = ruisekiwa[i] + u_or_d[i];
        }


        bool check = [&]() {
            ll count = 0;
            for (ll x = 0; x < n; x++) {
                for (ll y = x; y < n; y++) {
                    ll rw = ruisekiwa[y + 1] - ruisekiwa[x];
                    if (rw >= 0) {
                        count++;
                    } else {
                        count--;
                    }
                }
            }
            return count >= 0;
        }();


        if (!check) {
            cell = mid;
        } else {
            floor = mid;
        }
    }
    cout << floor << endl;


}