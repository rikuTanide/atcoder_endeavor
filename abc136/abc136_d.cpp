#include <bits/stdc++.h>
#include <cmath>

//using namespace boost::multiprecision;
using namespace std;
//typedef long long ll;
//typedef unsigned long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
//typedef pair<int, int> P;
//typedef pair<ll, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX / 100;
//const ll INF = (1ll << 31) - 1;
//const ll INF = 1e15;
//const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
//typedef pair<int, int> P;
//typedef pair<double, double> P;
#define ret() return 0;

bool contain(set<char> &s, char a) { return s.find(a) != s.end(); }

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
const int mod = 1000000007;
//const ll mod = 1e10;
typedef priority_queue<long long, vector<long long>, greater<long long> > PQ_ASK;

int main() {
    string s;
    cin >> s;

    vector<int> r(s.size());
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'R') r[i] = i;
        else {
            r[i] = r[i - 1];
        }
    }
    vector<int> l(s.size());
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == 'L') l[i] = i;
        else l[i] = l[i + 1];
    }

    vector<int> ans(s.size(), 0);

    rep(i, s.size()) {
        if (s[i] == 'L') {
            int nr = r[i];
            if ((i - nr) % 2 == 0) {
                ans[nr]++;
            } else {
                ans[nr + 1]++;
            }
        } else {
            int nl = l[i];
            if ((nl - i) % 2 == 0) {
                ans[nl]++;
            } else {
                ans[nl - 1]++;
            }
        }
    }
    for (int i : ans) printf("%d ", i);
}

