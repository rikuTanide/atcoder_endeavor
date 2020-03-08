#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<double, double> P;
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

ll pow2(ll a, ll b) {
    if (b == 0) return 1;
    ll res = a;
    for (ll i = 1; i < b; i++) {
        res *= a;
    }
    return res;
}

int top(int i) {
    return i / (pow2(10, log10(i)));
}

int back(int i) {
    return i % 10;
}

int main() {
    vector<vector<int>> counter(10, vector<int>(10, 0));

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int t = top(i);
        int b = back(i);
        counter[t][b]++;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int t = top(i);
        int b = back(i);
        ll count = counter[b][t];
        ans += count;
    }
    cout << ans << endl;
}
