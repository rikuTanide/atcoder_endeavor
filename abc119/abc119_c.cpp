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

//const ll mod = 1e10;
typedef priority_queue<string, vector<string>, greater<string> > PQ_ASK;

#include <iostream>
#include <vector>

using namespace std;

const int mod = 1000000007;

void dfs(int n, int depth, vector<int> route, vector<vector<int>> &candidate) {
    if (n == depth) {
        candidate.push_back(route);
        return;
    }
    rep(i, 4) {
        vector<int> route2 = route;
        route2.push_back(i);
        dfs(n, depth + 1, route2, candidate);
    }
}


int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    vector<ll> bamboos(n);
    rep(i, n) cin >> bamboos[i];

    vector<vector<int>> candidate;
    vector<int> route;
    dfs(n, 0, route, candidate);


    ll ans = INF;
    for (auto &l : candidate) {
        ll a_sum = 0, b_sum = 0, c_sum = 0;
        int a_count = 0, b_count = 0, c_count = 0;

        rep(i, n) {
            int bamboo = l[i];
            ll size = bamboos[i];
            if (bamboo == 0) {
                continue;
            }
            if (bamboo == 1) {
                a_sum += size;
                a_count++;
            }
            if (bamboo == 2) {
                b_sum += size;
                b_count++;
            }
            if (bamboo == 3) {
                c_sum += size;
                c_count++;
            }
        }
        if (a_sum == 0 || b_sum == 0 || c_sum == 0) continue;

        if (a_count > a) continue;
        if (b_count > b) continue;
        if (c_count > c) continue;

        ll sum = 0;
        sum += ((a_count - 1) * 10);
        sum += ((b_count - 1) * 10);
        sum += ((c_count - 1) * 10);

        sum += abs(a - a_sum);
        sum += abs(b - b_sum);
        sum += abs(c - c_sum);
        cmin(ans, sum);
    }

    cout << ans << endl;

}
