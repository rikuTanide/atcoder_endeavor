#include <bits/stdc++.h>
#include <cmath>

//using namespace boost::multiprecision;
using namespace std;
typedef long long ll;
//typedef unsigned long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
typedef pair<int, int> P;
//typedef pair<ll, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX / 100;
//const ll INF = (1ll << 31) - 1;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
//typedef pair<int, int> P;
//typedef pair<double, double> P;

bool contain(set<string> &s, string a) { return s.find(a) != s.end(); }

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
const int mod = 1000000007;
typedef priority_queue<long long, vector<long long>, greater<long long> > PQ_ASK;

bool is_mosho(double ma, double mi) {
    return 35 <= ma;
}

bool is_manatsu(double ma, double mi) {
    return 30 <= ma && ma < 35;
}

bool is_natsubi(double ma, double mi) {
    return 25 <= ma && ma < 30;
}

bool is_nettaiya(double ma, double mi) {
    return 25 <= mi;
}

bool is_fuyu(double ma, double mi) {
    return mi < 0 && 0 <= ma;
}

bool is_mafuyu(double ma, double mi) {
    return ma < 0;
}


int main() {
    int n;
    cin >> n;

    int mosho = 0,
            manatsu = 0,
            natsubi = 0,
            nettaiya = 0,
            fuyu = 0,
            mafuyu = 0;

    rep(i, n) {
        double ma, mi;
        cin >> ma >> mi;

        if (is_mosho(ma, mi)) {
            mosho++;
        }
        if (is_manatsu(ma, mi)) {
            manatsu++;
        }
        if (is_natsubi(ma, mi)) {
            natsubi++;
        }
        if (is_nettaiya(ma, mi)) {
            nettaiya++;
        }
        if (is_fuyu(ma, mi)) {
            fuyu++;
        }
        if (is_mafuyu(ma, mi)) {
            mafuyu++;
        }
    }

    printf("%d %d %d %d %d %d\n",
           mosho,
           manatsu,
           natsubi,
           nettaiya,
           fuyu,
           mafuyu
    );
}
