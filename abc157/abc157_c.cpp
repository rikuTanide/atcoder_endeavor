#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
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


int main() {
    int n, m;
    cin >> n >> m;
    vector<int> digits(n, -1);
    vector<P> conditions(m);
    rep(i, m) cin >> conditions[i].first >> conditions[i].second;
    rep(i, m) conditions[i].first--;
    for (P p : conditions) {
        digits[p.first] = p.second;
    }

    if (n == 1) {
        if (digits[0] == -1) digits[0] = 0;
    } else {
        rep(i, n) {
            if (i == 0 && digits[0] == -1) digits[0] = 1;
            else if (digits[i] == -1)digits[i] = 0;
        }
    }

    for (P p : conditions) {
        if (digits[p.first] != p.second) {
            cout << -1 << endl;
            ret();
        }
    }

    if (digits.size() > 1 && *max_element(digits.begin(), digits.end()) == 0) {
        cout << -1 << endl;
        ret();
    }

    int ans = 0;
    rep(i, n) {
        ans *= 10;
        ans += digits[i];
    }
    cout << ans << endl;
}
