#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<string> &o) {
    string a;
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

typedef pair<int, int> P;

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

bool check(ll n, vector<ll> &mechanics, ll time) {
    ll prev = -1;
    rep(i, mechanics.size()) {

        if (prev >= mechanics[i]) {
            prev = mechanics[i] + time;
            continue;
        }

        ll l = mechanics[i] - prev - 1;
        if (l > time) return false;
        ll lrr = max(time - (2 * l), 0ll);
        ll rll = (time - l) / 2;
        ll ma = max(lrr, rll);
        prev = mechanics[i] + ma;
    }
    return prev >= (n - 1);
}

int main() {
    ll n, m;
    cin >> n >> m;

    vector<ll> mechanics(m);
    rep(i, m) cin >> mechanics[i], mechanics[i]--;
    {
        bool b = check(n, mechanics, 0);
        if (b) {
            cout << 0 << endl;
            ret();
        }
    }
    ll floor = 0, ceil = INF;
    while (floor + 1 < ceil) {
        ll mid = (floor + ceil) / 2;
        bool b = check(n, mechanics, mid);
        if (b) ceil = mid;
        else floor = mid;
    }
    cout << ceil << endl;
}
