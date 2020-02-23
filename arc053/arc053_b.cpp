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

    string s;
    cin >> s;
    vector<int> counter(26);
    for (char c : s) counter[c - 'a']++;

    PQ_ASK q;
    rep(i, 27) {
        int j = counter[i];
        if (j % 2 == 1) {
            q.push(1);
            counter[i]--;
        }
    }

    if (q.empty()) q.push(0);

    for (int i : counter) assert(i % 2 == 0);

    for (int i : counter) {
        i /= 2;
        for (int j = 0; j < i; j++) {
            int k = q.top();
            q.pop();
            k += 2;
            q.push(k);
        }
    }

    cout << q.top() << endl;

}