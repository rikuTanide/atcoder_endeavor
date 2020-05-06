#include <bits/stdc++.h>


using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
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

typedef pair<ll, double> P;

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

// https://tokumini.hatenablog.com/entry/2018/07/23/182500

ll dfs(int to, vector<vector<int>> &loser) {
    if (loser[to].empty()) return 0;
    vector<int> nums;
    for (int l : loser[to]) nums.push_back(dfs(l, loser));
    sort(nums.rbegin(), nums.rend());
    rep(i, nums.size()) nums[i] += (i + 1);
    return *max_element(nums.begin(), nums.end());

}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) if (i != 0) cin >> a[i], a[i]--;
    vector<vector<int>> loser(n);
    rep(i, n) if (i != 0) loser[a[i]].push_back(i);

    cout << dfs(0, loser) << endl;

}
