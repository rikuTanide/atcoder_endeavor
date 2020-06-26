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

int main() {
    ll x, y;
    cin >> x >> y;

    ll sum = 0;

    if (abs(y) < abs(x)) {
        // 絶対値を小さくしないといけないから
        // x をマイナスにする
        if (x > 0) {
            sum++;
            x = -x;
        }
    } else if (abs(x) < abs(y)) {
        // 絶対値を大きくしないといけないから
        // xをプラスにする
        if (x < 0) {
            sum++;
            x = -x;
        }
    }
    ll add = abs(abs(x) - abs(y));
    x += add;
    sum += add;

    assert(x == y || (-x) == y);
    if (x != y) {
        sum++;
        x = -x;
    }

    assert(x == y);

    cout << sum << endl;

}
