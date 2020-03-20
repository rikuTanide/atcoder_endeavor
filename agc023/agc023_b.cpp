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
const int ROW_MAX = 100;

int main() {
    int n;
    cin >> n;
    vector<vector<char>> a(n, vector<char>(n));
    rep(i, n) rep(j, n) cin >> a[i][j];

    auto check = [&](int x) {
        vector<vector<char>> b(n, vector<char>(n));
        rep(i, n) rep(j, n) {
                b[i][j] = a[(i + x) % n][j];
            }
        rep(i, n) rep(j, n) {
                if (b[i][j] != b[j][i]) return false;
            }
        return true;
    };

    int ans = 0;
    rep(x, n) {
        if (check(x)) ans++;
    }
    cout << ans * n << endl;
}


