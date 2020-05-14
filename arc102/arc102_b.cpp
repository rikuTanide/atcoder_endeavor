#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
//typedef pair<double, double> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<string> &o) {
    string a;
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

// https://atcoder.jp/contests/arc102/submissions/3123383
// https://betrue12.hateblo.jp/entry/2018/09/02/094954
int main() {
    int j, k;
    int l, n = 0;
    cin >> l;
    while (1 << n <= l) n++;
    vector<vector<int>> ans;
    for (int i = 1; i < n; i++) {
        ans.push_back({i, i + 1, 1 << (i - 1)});
        ans.push_back({i, i + 1, 0});
    }

    int now = (1 << (n - 1)) - 1;

    for (int i = n - 1; i >= 1; i--) {
        if (now == l - 1) break;
        int gain = 1 << (i - 1);
        if (now + gain <= l - 1) {
            ans.push_back({i, n, now + 1});
            now += gain;
        }
    }

    int m = ans.size();
    cout << n << ' ' << m << endl;
    for (auto &v : ans) {
        printf("%d %d %d\n", v[0], v[1], v[2]);
    }

}
