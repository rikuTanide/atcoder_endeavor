#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
//typedef pair<ll, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX / 100;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<char> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    reverse(s.begin(), s.end());
    vector<int> sum(n + 1, 0);
    rep(i, n + 1) {
        if (s[i] == '0') sum[i] = 0;
        else sum[i] = sum[i - 1] + 1;
    }
    vector<int> ans;
    int now = 0;
    while (now != n) {
        int next = now + m;
        if (s[next] == '1') {
            next -= sum[next];
            if (now == next) {
                cout << -1 << endl;
                return 0;
            }
        }
        if (next > n) {
            next = n;
        }
        int distance = next - now;
        ans.push_back(distance);
        now = next;
    }

    reverse(ans.begin(), ans.end());
    for (int i : ans) {
        cout << i << ' ';
    }
    cout << endl;
}