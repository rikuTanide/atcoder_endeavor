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
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    vector<vector<char>> ans(ROW_MAX, vector<char>(ROW_MAX));
    rep(y, ROW_MAX / 2) rep(x, ROW_MAX) ans[y][x] = '#';
    rep(y, ROW_MAX / 2) rep(x, ROW_MAX) ans[ROW_MAX / 2 + y][x] = '.';

    rep(i, a) {
        int j = i * 2;
        int x = j % (ROW_MAX - 2) + 1;
        int y = j / (ROW_MAX - 2) * 2;

        ans[y][x] = '.';
    }

    rep(i, b) {
        int j = i * 2;
        int rx = j % (ROW_MAX - 2) + 1;
        int ry = j / (ROW_MAX - 2) * 2;

        int y = ROW_MAX - ry - 1;
        ans[y][rx] = '#';
    }

    printf("100 100\n");
    rep(y, ROW_MAX) {
        rep(x, ROW_MAX) {
            cout << ans[y][x];
        }
        cout << endl;
    }


}


