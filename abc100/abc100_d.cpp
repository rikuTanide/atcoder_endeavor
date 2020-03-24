#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
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

struct Cake {
    ll beauty, delicious, popular;

    ll sum() {
        return beauty + delicious + popular;
    }
};

vector<Cake> rev(vector<Cake> ary, int n, int i) {
    if (i & 1) {
        rep(j, n) ary[j].beauty *= -1;
    }
    if ((i >> 1) & 1) {
        rep(j, n) ary[j].delicious *= -1;
    }
    if ((i >> 2) & 1) {
        rep(j, n) ary[j].popular *= -1;
    }
    return ary;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Cake> cakes(n);
    rep(i, n) cin >> cakes[i].beauty >> cakes[i].delicious >> cakes[i].popular;

    vector<ll> candidate;

    for (int i = 0; i < (1 << 3); i++) {
        vector<Cake> tmp_cakes = rev(cakes, n, i);
        sort(tmp_cakes.rbegin(), tmp_cakes.rend(), [&](Cake &c, Cake &d) {
            return c.sum() < d.sum();
        });
        ll now = accumulate(tmp_cakes.begin(), tmp_cakes.begin() + m, 0ll, [&](ll prev, Cake &c) {
            return prev + c.sum();
        });
        candidate.push_back(now);
    }
    cout << *max_element(candidate.begin(), candidate.end()) << endl;
}



