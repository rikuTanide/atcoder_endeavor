#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
//typedef long long ll;
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = 10e15;
const ll MINF = -10e10;
const int INF = INT_MAX / 100;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("~/Downloads/02.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;

int main() {
    ll n, d, a;
    cin >> n >> d >> a;

    vector<P> temp(n);
    rep(i, n) cin >> temp[i].first >> temp[i].second;
    sort(temp.begin(), temp.end());

    vector<ll> hit_points(n);
    vector<ll> positions(n);

    rep(i, n) positions[i] = temp[i].first;
    rep(i, n) hit_points[i] = (temp[i].second + a - 1) / a;


    ll count = 0;
    for (ll i = 0; i < n; i++) {
        ll attack = hit_points[i];
        if (attack == 0) continue;
        count += attack;
        ll start_position = positions[i];
        ll end_position = start_position + (d + d);
        for (ll j = i; j < n && positions[j] <= end_position; j++) {
            hit_points[j] -= attack;
            if (hit_points[j] < 0) hit_points[j] = 0;
        }
    }
    cout << count << endl;

}
