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

void lose(int i) {
    if (i % 2 == 0) {
        cout << "LOSE" << endl;
    } else {
        cout << "WIN" << endl;
    }
}

int main() {
    int n;
    cin >> n;
    set<string> used;
    string prev;
    rep(i, n) {
        string w;
        cin >> w;
        if (i == 0) {
            used.insert(w);
            prev = w;
        } else {
            if (prev.back() != w.front()) {
                lose(i);
                return 0;
            }
            if (contain(used, w)) {
                lose(i);
                return 0;
            }
            prev = w;
            used.insert(w);
        }
    }
    cout << "DRAW" << endl;
}
