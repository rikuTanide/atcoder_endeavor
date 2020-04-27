#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<ll, ll> P;
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

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;


vector<int> get_digits(vector<int> &digits, int p, int q, int r) {
    vector<int> v(digits.size());
    rep(i, p) {
        v[i] = digits[i];
    }
    v[p] = q;
    rep(i, digits.size()) {
        if (i <= p) continue;
        v[i] = r;
    }
    return v;
}

bool ok(vector<int> &digits, int k) {
    set<int> s;
    for (int i : digits) s.insert(i);
    return s.size() <= k;
}

ll to_l(vector<int> &digits) {
    ll ans = 0;
    for (int i : digits) {
        ans *= 10;
        ans += i;
    }
    return ans;
}

int main() {
    ll a;
    int k;
    cin >> a >> k;

    vector<int> digits;
    {
        ll b = a;
        while (b != 0) {
            digits.push_back(b % 10);
            b /= 10;
        }
        reverse(digits.begin(), digits.end());
    }
    ll ans = INF;
    rep(p, digits.size()) {
        rep(q, 10) {
            rep(r, 10) {
                vector<int> v = get_digits(digits, p, q, r);
                bool b = ok(v, k);
                if (!b) continue;
                ll l = to_l(v);
                ll diff = abs(a - l);
                cmin(ans, diff);
            }
        }
    }
    cout << ans << endl;
}
