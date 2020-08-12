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

ll f(ll l) {
    int ans = 0;
    while (l > 0) {
        ans++;
        l %= __builtin_popcountll(l);
    }
    return ans;
}

int main() {

    int n;
    string s;
    cin >> n >> s;
    reverse(s.begin(), s.end());

    int pc = count(s.begin(), s.end(), '1');

    auto fac = [&](int i) -> vector<int> {
        vector<int> v(n, 0);
        int prev = 1 % i;
        rep(j, n) {
            v[j] = prev;
            prev *= 2;
            prev %= i;
        }
        return v;
    };

    vector<int> fac_up = fac(pc + 1);
    vector<int> fac_down = fac(pc - 1);

    auto ini = [&](int i, vector<int> &fac) -> int {
        if (i == 0) return -1;
        int prev = 0;
        rep(j, n) {
            if (s[j] == '1') prev += fac[j];
            prev %= i;
        }
        return prev;
    };

    int ini_up = ini(pc + 1, fac_up);
    int ini_down = ini(pc - 1, fac_down);

    vector<int> ans;
    rep(i, n) {
        if (s[i] == '0') {
            int pu = pc + 1;
            int now = (pu + ini_up + fac_up[i]) % pu;
            ans.push_back(f(now) + 1);
        } else {
            int pd = pc - 1;
            if (pd == 0) {
                ans.push_back(0);
                continue;
            }

            int now = (pd + ini_down - fac_down[i]) % pd;
            ans.push_back(f(now) + 1);
        }
    }

    reverse(ans.begin(), ans.end());


    for (int i : ans) cout << i << endl;

}
