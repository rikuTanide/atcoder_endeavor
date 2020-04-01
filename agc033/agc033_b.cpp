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

ll gcd(ll x, ll y) {
    if (x > y) swap(x, y);
    ll m = 1;
    while (m != 0) {
        m = y % x;
        y = x;
        x = m;
    }
    return y;
}

int main() {
    int h, w, n, sy, sx;
    cin >> h >> w >> n >> sy >> sx;

    sy--;
    sx--;

    string s, t;
    cin >> s >> t;

    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());

    int l = 0, r = w - 1, u = 0, d = h - 1;

    rep(i, n) {
        if (i == 0) {
            char c = s[0];
            if (c == 'L') l++;
            else if (c == 'R') r--;
            else if (c == 'U') u++;
            else if (c == 'D') d--;
        } else {
            char tc = t[i], sc = s[i];
            if (tc == 'L') {
                r = min(w - 1, r + 1);
            } else if (tc == 'R') {
                l = max(0, l - 1);
            } else if (tc == 'U') {
                d = min(h - 1, d + 1);
            } else if (tc == 'D') {
                u = max(0, u - 1);
            }
            if (sc == 'L') {
                l++;
            } else if (sc == 'R') {
                r--;
            } else if (sc == 'U') {
                u++;
            } else if (sc == 'D') {
                d--;
            }
            if (l > r || u > d) {
                cout << "NO" << endl;
                ret();
            }
        }
    }
    if (l <= sx && sx <= r && u <= sy && sy <= d) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

}
