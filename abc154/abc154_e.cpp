#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
//typedef pair<ll, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX / 10;
//const ll INF = (1ll << 31) - 1;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
//typedef pair<int, int> P;
//typedef pair<double, double> P;

bool contain(set<P> &s, P a) { return s.find(a) != s.end(); }

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);


void print_line(vector<ll> &line) {
    if (line.size() == 0ll) {
        cout << endl;
        return;
    }
    for (ll i = 0; i < line.size(); i++) {
        cout << line[i];
        if (i == line.size() - 1) cout << endl;
        else cout << ' ';
    }
}


typedef priority_queue<long long, vector<long long>, greater<long long>> PQ_ASK;
const int mod = 1000000007;


int main() {
    string n;
    int k;
    cin >> n >> k;

    vector<int> numbers;

    //ベクターnを構成
    for (auto a : n) {
        numbers.push_back(a - '0');
    }
    int l = n.size();  //nの長さ

    vector<vector<vector<ll>>> dp(l + 1, vector<vector<ll>>(2, vector<ll>(5, 0)));

    dp[0][0][0] = 1;  //初期条件。他は0で初期化されている
    for (int i = 0; i < l; i++) {
        for (int smaller = 0; smaller < 2; smaller++) {
            for (int j = 0; j < 5; j++) {
                for (int x = 0; x <= (smaller ? 9 : numbers[i]); x++) {
                    if (x != 0) {
                        dp[i + 1][smaller || x < numbers[i]][min(j + 1, 4)] += dp[i][smaller][j];
                    } else {
                        dp[i + 1][smaller || x < numbers[i]][j] += dp[i][smaller][j];
                    }
                }
            }
        }
    }

    cout << dp[l][0][k] + dp[l][1][k] << endl;

}


