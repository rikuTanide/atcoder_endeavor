#include <bits/stdc++.h>
#include <cmath>

//using namespace boost::multiprecision;
using namespace std;
typedef long long ll;
//typedef unsigned long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
typedef pair<int, int> P;
//typedef pair<ll, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX / 100;
//const ll INF = (1ll << 31) - 1;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
//typedef pair<int, int> P;
//typedef pair<double, double> P;

bool contain(set<string> &s, string a) { return s.find(a) != s.end(); }

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
const int mod = 1000000007;
typedef priority_queue<long long, vector<long long>, greater<long long> > PQ_ASK;

struct Tempo {
    int length;
    char type;
};

int main() {
    int n;
    cin >> n;

    int ans = 0;

    vector<string> music(n);
    rep(i, n) cin >> music[i];

    rep(i, 9) {
        stack<Tempo> s;

        rep(j, n) {
            char c = music[j][i];
            if (s.empty() || s.top().type != c) {
                s.push({1, c});
            } else if (c == 'x') {
                s.top().length++;
            }
        }
        while (!s.empty()) {
            Tempo t = s.top();
            s.pop();
            if (t.type == 'o' || t.type == 'x') {
                ans += t.length;
            }
        }
    }
    cout << ans << endl;
}
