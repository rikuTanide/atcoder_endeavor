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

struct Lottery {
    int count;
    int cost;
    int bits = 0;
    vector<double> rates;

    Lottery(int n) : rates(n) {}


};

std::istream &operator>>(std::istream &in, Lottery &o) {
    cin >> o.count;
    cin >> o.cost;
    rep(i, o.count) {
        int idol;
        cin >> idol;
        idol--;
        cin >> o.rates[idol];
        o.rates[idol] /= 100;
        o.bits |= (1 << idol);

    }

    return in;
}

// http://www.creativ.xyz/arc016c-605/
int main() {
    int n, m;
    cin >> n >> m;

    vector<Lottery> lotteries(m, Lottery(n));

    rep(i, m)cin >> lotteries[i];

    int state_max = 1 << n;


    vector<double> dp(state_max, INF);
    dp.back() = 0;

    for (int i = state_max - 1; i >= 0; i--) {
        for (Lottery &lottery: lotteries) {
            double success = 0;

            rep(j, n) {
                bool has = lottery.rates[j];
                bool needs = ((i >> j) & 1) == 0;
                if (has && needs) success += lottery.rates[j];
            }

            if (success == 0) continue;
            double expect = lottery.cost / success;

            rep(j, n) {
                bool has = lottery.rates[j];
                bool needs = ((i >> j) & 1) == 0;
                int next = i | (1 << j);
                if (has && needs) expect += lottery.rates[j] / success * dp[next];
            }

            cmin(dp[i], expect);
        }
    }

    printf("%.20f\n", dp[0]);
}