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

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
const int mod = 1000000007;
typedef priority_queue<long long, vector<long long>, greater<long long> > PQ_ASK;


int main() {
    set<int> es;
    rep(i, 6) {
        int e;
        cin >> e;
        es.insert(e);
    }
    int b;
    cin >> b;
    set<int> ls;
    rep(i, 6) {
        int l;
        cin >> l;
        ls.insert(l);
    }

    int match = 0;
    for (int e : es) {
        if (contain(ls, e)) {
            match++;
        }
    }

    if (match == 6) {
        cout << 1 << endl;
        return 0;
    }

    if (match == 5 && contain(ls, b)) {
        cout << 2 << endl;
        return 0;
    }

    if (match == 5) {
        cout << 3 << endl;
        return 0;
    }

    if (match == 4) {
        cout << 4 << endl;
        return 0;
    }

    if (match == 3) {
        cout << 5 << endl;
        return 0;
    }

    cout << 0 << endl;

}
