#include <bits/stdc++.h>
#include <cmath>


#include <assert.h>    // LON
#include <math.h>    // sqrt()


using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX;
const ll MINF = -10e10;
//const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;


int main() {
    int n;
    cin >> n;

    vector<ll> parents(n, -1);
    vector<ll> distances(n, -1);

    rep(i, n - 1) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        parents[b] = a;
        distances[b] = c;
    }

    ll q, k;
    cin >> q >> k;
    k--;
    map<ll, ll> k_distances;
    {
        k_distances[k] = 0;
        ll now = k;
        ll distance = 0;
        while (parents[now] > -1) {

            k_distances[parents[now]] = distance + distances[now];
            distance += distances[now];
            now = parents[now];
        }
    }
    rep(i, q) {
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        ll x_distance;
        ll y_distance;
        {
            ll now = x;
            ll distance = 0;
            while (true) {
                if (k_distances.find(now) != k_distances.end()) {
                    x_distance = distance + k_distances[now];
                    break;
                }
                distance += distances[now];
                now = parents[now];
            }
        }
        {
            ll now = y;
            ll distance = 0;
            while (true) {
                if (k_distances.find(now) != k_distances.end()) {
                    y_distance = distance + k_distances[now];
                    break;
                }
                distance += distances[now];
                now = parents[now];
            }
        }

        cout << x_distance + y_distance << endl;

    }

}