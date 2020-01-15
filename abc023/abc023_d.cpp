#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;

struct Balloon {
    ll initial;
    ll speed;
};

ll check(Balloon balloon, ll score) {
    ll t = (score - balloon.initial) / balloon.speed;
    return t;
}

bool check_all(vector<Balloon> &balloons, ll score) {
    vector<ll> times(balloons.size());
    for (ll i = 0; i < balloons.size(); i++) {
        Balloon balloon = balloons[i];
        ll time = check(balloon, score);
        if (time < 0) return false;
        times[i] = time;
    }
    sort(times.begin(), times.end());
    for (ll i = 0; i < balloons.size(); i++) {
        if (times[i] < i) return false;
    }
    return true;
}

int main() {
    ll n;
    cin >> n;

    vector<Balloon> balloons(n);
    rep(i, n) {
        cin >> balloons[i].initial;
        cin >> balloons[i].speed;
    }

    ll floor = 0;
    ll ceil = INF;
    while (floor + 1 < ceil) {
        ll mid = (floor + ceil) / 2;
        bool b = check_all(balloons, mid);

        if (b) {
            ceil = mid;
        } else {
            floor = mid;
        }
    }

    cout << ceil << endl;


}
