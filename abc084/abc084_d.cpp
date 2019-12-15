#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = 10e15;
const ll MINF = -10e10;
//const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;

const int INF = 100000 + 1000;

map<int, bool> factors;

bool isFactor(int n) {
    if (n == 1) return false;
    if (n == 2) return true;
    if (factors.find(n) != factors.end()) return factors[n];

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            factors[n] = false;
            return false;
        }
    }
    factors[n] = true;
    return true;
}

int main() {
    vector<ll> like_2017_sum(INF, 0);
    for (int i = 3; i <= INF; i++) {
        if (isFactor(i) && isFactor((i + 1) / 2)) {
            like_2017_sum[i] = like_2017_sum[i - 1] + 1;
        } else {
            like_2017_sum[i] = like_2017_sum[i - 1];
        }
    }

    int q;
    cin >> q;
    rep(i, q) {
        int l, r;
        cin >> l >> r;

        cout << (like_2017_sum[r] - like_2017_sum[l - 1]) << endl;
    }

}