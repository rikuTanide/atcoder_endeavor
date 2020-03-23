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


int main() {
    int n;
    cin >> n;

    vector<int> numbers(n);
    rep(i, n) cin >> numbers[i];
    rep(i, n) numbers[i]--;

    vector<int> indexes(n);
    rep(i, n) indexes[numbers[i]] = i;

    vector<int> dp(n, 0);

    rep(i, n) {
        if (i == 0) continue;
        int ii = indexes[i];
        int bi = indexes[i - 1];
        if (bi < ii) {
            dp[i] = 1;
        }
    }
    rep(i, n) {
        if (i == 0) continue;
        else if (dp[i] == 0) continue;
        else dp[i] += dp[i - 1];
    }


    int ma = *max_element(dp.begin(), dp.end());
    cout << n - ma - 1 << endl;

    cout << endl;

}



