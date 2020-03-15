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


int main() {
    int n;
    ll t;
    cin >> n >> t;

    vector<ll> apples(n);
    rep(i, n) cin >> apples[i];

    vector<ll> max_prices(n);
    max_prices.back() = apples.back();
    for (int i = n - 2; i >= 0; i--) {
        max_prices[i] = max(max_prices[i + 1], apples[i]);
    }

    ll max_diff = 0;
    rep(i, n) cmax(max_diff, max_prices[i] - apples[i]);


    int ans = 0;
    rep(i, n) if (max_prices[i] - apples[i] == max_diff) ans++;
    cout << ans << endl;

}
