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
//const ll INF = 10e15;
const ll MINF = -10e10;
const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;

struct Train {
    ll time;
    ll start;
    ll between;

    ll next(ll t) {
        if (t <= start) {
            return start + time;
        }
        ll s = t - start;
        ll maega_ittekara_byougo = s % between;
        if (maega_ittekara_byougo == 0) {
            return t + time;
        }
        ll mati = between - maega_ittekara_byougo;
        return t + mati + time;
    }

};

int main() {

    ll n;
    cin >> n;

    vector<Train> trains(n - 1);

    rep(i, n - 1) {
        ll c, s, f;
        cin >> c >> s >> f;
        Train t = {c, s, f};
        trains[i] = t;
    }

    for (ll start_station = 0; start_station < n; start_station++) {
        ll time = 0;
        for (ll current_station = start_station; current_station < n - 1; current_station++) {

            Train t = trains[current_station];
            ll next = t.next(time);
            time = next;
        }
        cout << time << endl;
    }


}