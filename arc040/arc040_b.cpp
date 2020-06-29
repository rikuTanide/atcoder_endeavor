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
    int n, r;
    string s;
    cin >> n >> r >> s;


    vector<bool> shot(n, false);

    bool need = false;
    int l = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (!need && s[i] == '.') {
            need = true;
            l = i;
        }

        if (need && (i + (r - 1) == l || i == 0)) {
            shot[i] = true;
            need = false;
            l = -1;
        }
    }
    int sc = count(shot.begin(), shot.end(), true);
    if (sc == 0) {
        cout << 0 << endl;
        ret();
    }
    int right = 0;
    rep(i, n) {
        if (shot[i]) right = i;
    }

    int ans = sc + right;
    cout << ans << endl;

}
