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
const ll INF = LONG_LONG_MAX;
const ll MINF = -10e10;
//const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;

int main() {

    int n;
    cin >> n;
    vector<int> training_system(n);
    rep(i, n) {
        int a;
        cin >> a;
        a--;
        training_system[i] = a;
    }

    int now = 0;
    int count = 0;
    while (now != 1 && now != -1) {
        int k = training_system[now];
        training_system[now] = -1;
        now = k;
        count++;
    }
    if (now == 1) {
        cout << count << endl;
    } else {
        cout << "-1" << endl;
    }

}