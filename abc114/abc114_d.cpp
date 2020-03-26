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

//const ll mod = 1e10;
typedef priority_queue<string, vector<string>, greater<string> > PQ_ASK;

#include <iostream>
#include <vector>

using namespace std;

const int mod = 1000000007;

map<ll, ll> factorize(ll n) {
    map<ll, ll> res;

    for (ll i = 2; i * i <= n; i++) {
        if (n % i != 0) {
            continue;
        }
        res[i] = 0;
        while (n % i == 0) {
            n /= i;
            res[i]++;
        }
    }


    if (n != 1) res[n] = 1;
    return res;

}


int main() {
    ll n;
    cin >> n;
    map<ll, ll> factors;
    for (ll i = 1; i <= n; i++) {
        map<ll, ll> f = factorize(i);
        for (auto e : f) {
            factors[e.first] += e.second;
        }
    }


    ll ans = 0;
    for (auto e : factors) {
        for (auto f : factors) {
            for (auto g : factors) {
                if (e.first == f.first) continue;
                if (f.first == g.first) continue;
                if (g.first == e.first) continue;
                if (f.first >= g.first) continue;

                if (e.second >= 2 && f.second >= 4 && g.second >= 4) ans++;

            }
        }
    }

    for (auto e : factors) {
        for (auto f : factors) {
            if (e.first == f.first) continue;
            if (e.second >= 2 && f.second >= 24) ans++;
        }
    }

    for (auto e : factors) {
        for (auto f : factors) {
            if (e.first == f.first) continue;
            if (e.second >= (5 - 1) && f.second >= (15 - 1)) ans++;
        }
    }

    for (auto e : factors) if (e.second >= 74) ans++;

    cout << ans << endl;
}
