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

int main() {
    string s, t;
    cin >> s >> t;

    s = s + s;

    vector<vector<int >> point(26);
    rep(i, s.size()) {
        char c = s[i];
        int j = c - 'a';
        point[j].push_back(i);
    }

    ll position = 0;
    rep(i, t.size()) {
        char c = t[i];
        int j = c - 'a';
        int ps = position % (s.size() / 2);
        auto it = lower_bound(point[j].begin(), point[j].end(), ps);
        if (it == point[j].end()) {
            cout << -1 << endl;
            ret();
        }
        int k = *it;
        int m = k - ps;
        position += m;
    }
    cout << position + 1 << endl;
}



