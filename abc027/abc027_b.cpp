#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
//using namespace boost::multiprecision;
using namespace std;
typedef long long ll;
//typedef unsigned long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
//typedef pair<int, int> P;
//typedef pair<ll, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX / 100;
//const ll INF = (1ll << 31) - 1;
const ll INF = 1e15;
//const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
//typedef pair<int, int> P;
//typedef pair<double, double> P;
#define ret() return 0;

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const int mod = 1000000007;
//const ll mod = 1e10;
typedef priority_queue<long long, vector<long long>, greater<long long> > PQ_ASK;

int main() {


    int n;
    cin >> n;

    vector<int> temp(n);
    rep(i, n)cin >> temp[i];

    int all = accumulate(temp.begin(), temp.end(), 0);
    if (all % n != 0) {
        cout << -1 << endl;
        ret();
    }

    int target = all / n;

    queue<int> islands;
    for (int i : temp) islands.push(i);

    int now = 0;
    int brides = 0;
    int count = 0;
    while (!islands.empty()) {
        now += islands.front();
        count++;
        islands.pop();
        if (now == target * count) {
            now = 0;
            count = 0;
        } else {
            brides++;
        }
    }

    if (now != 0) {
        cout << -1 << endl;
    } else {
        cout << brides << endl;
    }

}