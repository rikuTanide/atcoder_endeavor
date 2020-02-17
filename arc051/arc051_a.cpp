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
    vector<vector<char>> board(201, vector<char>(201, ' '));

    int x1, y1, r;
    cin >> x1 >> y1 >> r;
    int x2, y2, x3, y3;
    cin >> x2 >> y2 >> x3 >> y3;
    {
        // 円の左端
        int left = x1 - r;
        int right = x1 + r;
        int top = y1 + r;
        int bottom = y1 - r;

        if (x2 <= left && right <= x3 && y2 <= bottom && top <= y3) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }

    {
        auto inner_circle = [&](int x, int y) {
            double w = (x1 - x);
            double h = (y1 - y);
            double ww = w * w;
            double hh = h * h;
            double d = sqrt(ww + hh);
            bool ans = r >= d;
            return ans;
        };

        if (inner_circle(x2, y2) && inner_circle(x2, y3) && inner_circle(x3, y2) && inner_circle(x3, y3)) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }

    }



}
