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
    string s;
    ll k;

    cin >> s >> k;

    ll n = s.size();

    char f = s.front();
    char b = s.back();

    if (count(s.begin(), s.end(), f) == n) {
        cout << n * k / 2 << endl;
        ret();
    }

    ll sa = [&]() -> ll {
        string t = s;
        ll ans = 0;
        rep(i, n - 1) {
            if (t[i] == t[i + 1]) {
                ans++;
                t[i + 1] = '*';
            }
        }
        return ans;
    }();

    if (f != b) {
        cout << sa * k << endl;
        ret();
    }

    ll pre = [&]() -> ll {
        rep(i, n) {
            if (s[i] != f) return i;
        }
        __throw_runtime_error("konaide");
    }();

    ll suf = [&]() -> ll {
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] != b) return n - i - 1;
        }
        __throw_runtime_error("konaide");
    }();


    cout << sa * k - ((pre / 2 + suf / 2 - (pre + suf) / 2) * (k - 1)) << endl;

}
