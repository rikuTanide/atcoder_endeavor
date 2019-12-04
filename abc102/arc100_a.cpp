#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
typedef pair<int, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = 10e10;
const ll MINF = -10e10;
//const int INF = INT_MAX;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)

typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;
const int mod = 1000000007;
//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
typedef tuple<int, int, int> Q;


int main() {
    int n;
    cin >> n;

    vector<ll> as(n);
    rep(i, n) {
        cin >> as[i];
        as[i] -= i;
    }

    sort(as.begin(), as.end());
    if (n % 2 == 0) {

        ll a1 = [&] {
            ll m = as[n / 2 - 1];

            ll now = 0;
            rep(i, n) {
                now += abs(as[i] - m);
            }
            return now;
        }();

        ll a2 = [&] {
            ll m = as[n / 2];

            ll now = 0;
            rep(i, n) {
                now += abs(as[i] - m);
            }
            return now;
        }();
        cout << min(a1, a2) << endl;
        return 0;
    }

    ll m = as[n / 2];

    ll now = 0;
    rep(i, n) {
        now += abs(as[i] - m);
    }
    cout << now << endl;
}


