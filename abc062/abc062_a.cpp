#include <bits/stdc++.h>
#include <cmath>

#include <assert.h>    // LON
#include <math.h>    // sqrt()


using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX;
const ll MINF = -10e10;
const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;


bool contain(set<int> &s, int a) {
    return s.find(a) != s.end();
}

int main() {
    set<int> a = {
            1, 3, 5, 7, 8, 10, 12,
    };
    set<int> b = {4, 6, 9, 11};
    set<int> c = {2};

    int x, y;
    cin >> x >> y;

    if (
            contain(a, x) == contain(a, y)
            && contain(b, x) == contain(b, y)
            && contain(c, x) == contain(c, y)
            ) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }


}