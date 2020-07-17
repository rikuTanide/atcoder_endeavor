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

struct Key {
    int match, price;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Key> keys(m);

    rep(i, m) {
        int a, b;
        cin >> a >> b;

        int match = 0;
        rep(_, b) {
            int c;
            cin >> c;
            c--;
            int next = 1 << c;
            match |= next;
        }

        keys[i] = {match, a};
    }

    vector<int> dp(1 << n, -1);
    dp[0] = 0;
    for (Key key : keys) {
        rep(i, 1 << n) {
            if (dp[i] == -1) continue;
            int next_match = i | key.match;
            int next_price = dp[i] + key.price;
            if (dp[next_match] == -1) dp[next_match] = next_price;
            else
                cmin(dp[next_match], next_price);
        }
    }

    cout << dp[(1 << n) - 1] << endl;

}
