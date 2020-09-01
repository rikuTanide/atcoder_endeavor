#include <bits/stdc++.h>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

std::istream &operator>>(std::istream &in, set<ll> &o) {
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
//typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;


int main() {
    int n;
    cin >> n;

    vector<int> speeds = [&]() -> vector<int> {

        vector<int> _times(n), _speeds(n);
        rep(i, n) cin >> _times[i];
        rep(i, n) cin >> _speeds[i];

        vector<int> speeds;
        rep(i, n) {
            rep(j, _times[i]) speeds.push_back(_speeds[i]);
        }

        vector<int> speeds2;
        rep(i, speeds.size()) {
            if (i == 0) {
                speeds2.push_back(0);
                speeds2.push_back(speeds[0]);
            } else {
                int mi = min(speeds[i - 1], speeds[i]);
                speeds2.push_back(mi);
                speeds2.push_back(speeds[i]);

            }
        }
        speeds2.push_back(0);
        return speeds2;

    }();


    int ss = speeds.size();
    vector<double> dp(ss);
    rep(i, ss) dp[i] = speeds[i];
    rep(i, ss) if (i != 0) cmin(dp[i], dp[i - 1] + 0.5);
    for (int i = ss - 2; i > 0; i--) cmin(dp[i], dp[i + 1] + 0.5);

    double sum = 0;

    rep(i, ss) {
        if (i == 0) continue;
        double a = dp[i - 1], b = dp[i];
        double now = (a + b) / 2 * 0.5;
        sum += now;
    }

    cout << setprecision(20) << sum << endl;

}