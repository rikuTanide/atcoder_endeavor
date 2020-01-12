#include <bits/stdc++.h>
#include <cmath>

using namespace std;
//typedef long long ll;
typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX;
const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;


int main() {

    int n, m;
    cin >> n >> m;

    vector<bool> ok_list(n, false);
    vector<int> wa_counts(n, 0);

    int ok_count = 0;
    int wa_count = 0;

    rep(i, m) {
        int p;
        string judge;
        cin >> p >> judge;
        p--;

        if (ok_list[p] == false && judge == "AC") {
            ok_list[p] = true;
            ok_count++;
            wa_count += wa_counts[p];
        } else if (ok_list[p] == false && judge == "WA") {
            wa_counts[p]++;
        }
    }


    printf("%d %d\n", ok_count, wa_count);

}
