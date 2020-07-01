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
    int n;
    cin >> n;
    vector<string> v(n);
    rep(i, n) cin >> v[i];

    int ab = 0, ba = 0, bx = 0, xa = 0;

    for (string s: v) {
        rep(i, s.size() - 1) {
            if (s.substr(i, 2) == "AB") ab++;
        }
    }

    for (string s: v) {
        if (s.front() == 'B' && s.back() == 'A') ba++;
        else if (s.front() == 'B') bx++;
        else if (s.back() == 'A') xa++;
    }


    if (ba == 0) {
        int add = min(bx, xa);
        cout << add + ab << endl;
    } else {
        ll c = ba - 1 + ab;
        if (xa > 0) {
            xa--;
            c++;
        }
        if (bx > 0) {
            bx--;
            c++;
        }

        c += min(xa, bx);
        cout << c << endl;
    }

}
