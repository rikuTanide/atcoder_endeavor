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

    vector<ll> attack_points(n, 0);

    ll count = 0;
    for (ll i = 0; i < n; i++) {
        if (i > 0)attack_points[i] += attack_points[i - 1];
        ll attack = hit_points[i];
        attack -= attack_points[i];
        if (attack <= 0) continue;
        count += attack;
        attack_points[i] += attack;
        ll start_position = positions[i];
        ll end_position = start_position + (d + d);
        {
            auto it = upper_bound(positions.begin(), positions.end(), end_position);
            if (it == positions.end()) continue;
            int range = it - positions.begin();
            attack_points[range] -= attack;
        }

    }
    cout << count << endl;

}
