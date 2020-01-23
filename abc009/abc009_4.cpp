#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
//typedef long long ll;
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = 10e15;
const ll MINF = -10e10;
const int INF = INT_MAX / 100;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("~/Downloads/02.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;
// https://atcoder.jp/contests/abc009/submissions/9317894
// なんもわからん。

vector<vector<ll>> pro(const vector<vector<ll>> &a, const vector<vector<ll>> &b) {
    vector<vector<ll>> C(a.size(), vector<ll>(b[0].size()));

    rep(i, a.size()) {
        rep(j, b.size()) {
            rep(k, b[0].size()) {
                C[i][k] ^= (a[i][j] & b[j][k]);
            }
        }
    }
    return C;
}

vector<vector<ll>> power(vector<vector<ll>> A, int n) {
    vector<vector<ll>> B(A.size(), vector<ll>(A.size()));
    for (int i = 0; i < A.size(); i++) B[i][i] = (1LL << 60) - 1;
    while (n > 0) {
        if (n & 1) B = pro(B, A);
        A = pro(A, A);
        n >>= 1;
    }
    return B;
}

int main() {
    int k, m;
    cin >> k >> m;

    vector<vector<ll>> matrix_a(k, vector<ll>(k));
    vector<vector<ll>> matrix_b(k, vector<ll>(1));

    rep(i, k) {
        cin >> matrix_b[k - 1 - i][0];
    }
    rep(i, k) {
        cin >> matrix_a[0][i];
    }
    for (int i = 1; i < k; i++) {
        matrix_a[i][i - 1] = (1LL << 60) - 1;
    }

    if (m <= k) {
        cout << matrix_b[k - m][0] << endl;
        return 0;
    }


    vector<vector<ll>> x = power(matrix_a, m - 1);
    vector<vector<ll>> y = pro(x, matrix_b);
    cout << y[k - 1][0] << endl;

}
