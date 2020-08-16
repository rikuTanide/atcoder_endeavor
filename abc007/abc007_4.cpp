#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<int> &o) {
    int a;
    in >> a;
    o.insert(a);
    return in;
}

std::istream &operator>>(std::istream &in, queue<int> &o) {
    ll a;
    in >> a;
    o.push(a);
    return in;
}

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;


ll digit_dp(string N) {

    //Nは桁数が大きい場合があるので文字列として受け取る
    vector<int> n;  //Nの各桁の数字を格納するベクター
    vector<vector<vector<ll>>> dp(100, vector<vector<ll>>(2, vector<ll>(2, 0)));//[100][2][2];

    //ベクターnを構成
    for (auto a : N) {
        n.push_back(a - '0');
    }
    int l = N.size();  //nの長さ

    dp[0][0][0] = 1;  //初期条件。他は0で初期化されている
    for (int i = 0; i < l; i++) {
        for (int smaller = 0; smaller < 2; smaller++) {
            for (int j = 0; j < 2; j++) {
                for (int x = 0; x <= (smaller ? 9 : n[i]); x++) {
                    dp[i + 1][smaller || x < n[i]][j || (x == 4 || x == 9)] += dp[i][smaller][j];
                }
            }
        }
    }

    return dp[l][0][1] + dp[l][1][1];
}

int main() {
    ll a, b;
    cin >> a >> b;
    ll x = digit_dp(to_string(a - 1));
    ll y = digit_dp(to_string(b));

    cout << y - x << endl;

}