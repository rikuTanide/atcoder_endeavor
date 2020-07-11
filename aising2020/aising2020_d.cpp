#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

namespace mp = boost::multiprecision;

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


ll get_mod(string s, int pp) {
    mp::cpp_int i = 0;
    rep(j, s.size()) {
        i *= 2;
        i += s[j] == '1';
    }

    mp::cpp_int g = i % pp;
    ll f = static_cast<ll>(g);

//    cout << bitset<23>(f) << endl;

    return f;

}

ll f(ll n) {
    int ans = 1;
    while (n > 0) {
        ll pp = __builtin_popcountll(n);
        n %= pp;
        ans++;
    }
    return ans;
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    int pp = count(s.begin(), s.end(), '1');

    ll um = get_mod(s, pp + 1);
    ll dm = get_mod(s, pp - 1);


    auto create_md = [](int n, int pp) {
        vector<ll> md(n);

        ll prev = 1;
        rep(i, n) {
            md[i] = prev;
            prev *= 2;
            prev %= pp;
        }
        reverse(md.begin(), md.end());
        return md;
    };


    vector<ll> mdu = create_md(n, pp + 1);
    vector<ll> mdd = create_md(n, pp - 1);

    vector<ll> ans;

    rep(i, n) {
        if (s[i] == '0') {
            ll prev = (um + mdu[i]) % (pp + 1);
            ll now = f(prev);
            ans.push_back(now);
        } else {
            ll prev = (dm + mdd[i]) % (pp - 1);
            ll now = f(prev);
            ans.push_back(now);
        }
    }

//    sort(ans.begin(), ans.end());

    for (ll l : ans) cout << l << endl;

}
