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

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//const ll mod = 1e10;
typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

#include <iostream>
#include <vector>

using namespace std;

const int mod = 1000000007;


int main() {
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;

    vector<ll> red_temp(a), blue_temp(b);
    rep(i, a) cin >> red_temp[i];
    rep(i, b) cin >> blue_temp[i];
    sort(red_temp.rbegin(), red_temp.rend());
    sort(blue_temp.rbegin(), blue_temp.rend());


    PQ_ASK red, blue;
    rep(i, x) {
        red.push(red_temp[i]);
    }
    rep(i, y) {
        blue.push(blue_temp[i]);
    }

    vector<ll> white(c);
    rep(i, c) cin >> white[i];
    sort(white.rbegin(), white.rend());

    for (ll w : white) {
        if (red.top() < blue.top()) {
            if (w > red.top()) {
                red.pop();
                red.push(w);
            }
        } else {
            if (w > blue.top()) {
                blue.pop();
                blue.push(w);
            }
        }
    }


    ll ans = 0;

    while (!red.empty()) {
        ans += red.top();
        red.pop();
    }
    while (!blue.empty()) {
        ans += blue.top();
        blue.pop();
    }

    cout << ans << endl;
}
