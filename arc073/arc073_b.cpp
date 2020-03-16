#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<ll, int> P;
const ll INF = 1e15;
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

struct Item {
    ll weight, value;
};

int main() {
    int n;
    ll w;
    cin >> n >> w;
    vector<Item> items(n);
    rep(i, n) cin >> items[i].weight >> items[i].value;

    vector<map<ll, ll>> dp(n + 1);

    auto set = [&](int i, ll weight, ll value) {
        if (weight > w) return;
        if (dp[i].find(weight) == dp[i].end()) dp[i][weight] = value;
        else
            cmax(dp[i][weight], value);
    };
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        Item item = items[i];
        for (auto &e : dp[i]) {
            set(i + 1, e.first, e.second);
            set(i + 1, e.first + item.weight, e.second + item.value);
        }
    }

    ll ans = 0;
    for (auto e:  dp.back()) {
        cmax(ans, e.second);
    }
    cout << ans << endl;

}
