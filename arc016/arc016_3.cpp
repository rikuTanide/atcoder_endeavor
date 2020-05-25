#include <bits/stdc++.h>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<double, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

std::istream &operator>>(std::istream &in, set<int> &o) {
    ll a;
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

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//const ll mod = 1e10;
typedef priority_queue<string, vector<string>, greater<string> > PQ_ASK;


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


int main() {
    int n, m;
    cin >> n >> m;

    vector<Lottery> lotteries(m, Lottery(n));

    rep(i, m)cin >> lotteries[i];

    int state_max = 1 << n;


    vector<double> dp(state_max, INF);
    dp.back() = 0;

    for (int i = state_max - 1; i >= 0; i--) {
        double k = INF;
        for (Lottery &lottery: lotteries) {
            double sum = lottery.cost;
            rep(j, n) {
                double rate = lottery.rates[j];
                int next_bit = i | (1 << j);
                if (next_bit == i) continue;
                double now = rate * dp[next_bit];
                sum += now;
            }
            cmin(k, sum);
        }
        cmin(dp[i], k);
    }

    printf("%.20f\n", dp[0]);
}
