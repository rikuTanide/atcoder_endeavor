#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
using namespace std;
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

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
const int mod = 1000000007;
//const ll mod = 1e10;
typedef priority_queue<string, vector<string>, greater<string> > PQ_ASK;

#include <iostream>
#include <vector>

using namespace std;

struct Place {
    int x, y;
};

int main() {
    ll h, w, d;
    cin >> h >> w >> d;

    vector<vector<ll>> grid(h, vector<ll>(w));
    rep(y, h) rep(x, w) cin >> grid[y][x];
    rep(y, h) rep(x, w) grid[y][x]--;

    vector<Place> places(h * w);
    rep(y, h) rep(x, w) {
            ll i = grid[y][x];
            places[i].y = y;
            places[i].x = x;
        }

    auto diff = [](Place &p, Place &q) {
        return abs(p.x - q.x) + abs(p.y - q.y);
    };

    vector<ll> distances_sum(h * w, 0);
    for (ll i = 0; i < h * w; i++) {
        if (i - d < 0) continue;
        distances_sum[i] = diff(places[i], places[i - d]);
    }
    for (ll i = 0; i < h * w; i++) {
        if (i - d < 0) continue;
        distances_sum[i] += distances_sum[i - d];
    }


    int q;
    cin >> q;
    rep(i, q) {
        ll l, r;
        cin >> l >> r;
        l--;
        r--;
        ll end = distances_sum[r];
        ll start = distances_sum[l];

        cout << end - start << endl;
    }

}


