#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
//typedef pair<ll, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX / 100;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;

// https://qiita.com/pinokions009/items/1e98252718eeeeb5c9ab


class Keta {

    vector<int> digits;

public:
    Keta(ll i) : digits(log10(i) + 1) {
        for (int k = 0; k < digits.size(); k++) {
            digits[k] = i % 10;
            i /= 10;
        }
        reverse(digits.begin(), digits.end());
    }

    int keta() {
        return digits.size();
    }

    int get(int index) {
        assert(index < keta());
        return digits[index];
    }
};


ll check(Keta &keta) {
    vector<ll> digits;  //Nの各桁の数字を格納するベクター
    vector<vector<vector<ll>>> dp(100, vector<vector<ll>>(2, vector<ll>(2, 0)));

    ll l = keta.keta();  //nの長さ
    dp[0][0][0] = 1;
    for (ll i = 0; i < l; i++) {
        for (ll smaller = 0; smaller < 2; smaller++) {
            for (ll j = 0; j < 2; j++) {
                for (ll x = 0; x <= (smaller ? 9 : keta.get(i)); x++) {
                    dp[i + 1][smaller || x < keta.get(i)][j || (x == 4 || x == 9)] += dp[i][smaller][j];
                }
            }
        }
    }
    return dp[l][0][1] + dp[l][1][1];
}

int main() {
    ll a, b;
    cin >> a >> b;
    Keta ka(a - 1);
    Keta kb(b);
    cout << check(kb) - check(ka) << endl;
}
