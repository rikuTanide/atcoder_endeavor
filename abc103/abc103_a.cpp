#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
typedef pair<int, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = 10e10;
const ll MINF = -10e10;
const int INF = INT_MAX;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)

typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;
const int mod = 1000000007;
//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
typedef tuple<int, int, int> Q;


int main() {
    int a1, a2, a3;
    cin >> a1 >> a2 >> a3;

    int a1_a2 = abs(a2 - a1);
    int a2_a3 = abs(a3 - a2);
    int a3_a1 = abs(a3 - a1);


    int ans_1 = a1_a2 + a2_a3;
    int ans_2 = a2_a3 + a3_a1;
    int ans_3 = a3_a1 + a1_a2;

    int ans = INF;

    ans = min(ans, ans_1);
    ans = min(ans, ans_2);
    ans = min(ans, ans_3);

    cout << ans << endl;

}
