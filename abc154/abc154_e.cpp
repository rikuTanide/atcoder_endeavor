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

struct Monster {
    ll x, h;
};

std::istream &operator>>(std::istream &in, Monster &o) {
    cin >> o.x >> o.h;
    return in;
}

string N;
vector<int> n;  //Nの各桁の数字を格納するベクター
int dp[200][2][5];

int main() {
    cin >> N;

    int k;
    cin >> k;

    //ベクターnを構成
    for (auto a : N) {
        n.push_back(a - '0');
    }
    int l = N.size();  //nの長さ

    dp[0][0][0] = 1;  //初期条件。他は0で初期化されている
    for (int i = 0; i < l; i++) {
        for (int smaller = 0; smaller < 2; smaller++) {
            for (int j = 0; j < 4; j++) {
                for (int x = 0; x <= (smaller ? 9 : n[i]); x++) {
                    dp[i + 1][smaller || x < n[i]][j + (x != 0)] += dp[i][smaller][j];
                }
            }
        }
    }

    cout << dp[l][0][k] + dp[l][1][k] << endl;
}