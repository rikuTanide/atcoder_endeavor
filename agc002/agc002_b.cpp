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


int main() {
    int n, m;
    cin >> n >> m;
    vector<char> boxes(n, 'w');
    vector<int> boxes_c(n, 1);
    boxes[0] = 'r';
    rep(i, m) {
        int x, y;
        cin >> x >> y;

        x--;
        y--;

        char from = boxes[x], to = boxes[y];
        if (from == 'm') boxes[y] = 'm';
        else if (to == 'm') boxes[y] = 'm';
        else if (from == 'w' && to == 'w') boxes[y] = 'w';
        else if ((from == 'w' && to == 'r') || (from == 'r' && to == 'w')) boxes[y] = 'm';
        else if (to == 'n') boxes[y] = from;

        boxes_c[x]--;
        boxes_c[y]++;
        if (boxes_c[x] == 0) boxes[x] = 'n';

    }

    int ans = 0;

    for (char c : boxes) {
        if (c == 'r') {
            cout << 1 << endl;
            return 0;
        }
    }

    for (char b : boxes)if (b == 'm') ans++;
    cout << ans << endl;

}
