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

bool nine(string &s) {
    int i = distance(find(s.begin(), s.end(), '.'), s.end());
    return i == 10;
}

vector<ll> up(vector<string> &v) {
    vector<ll> res;
    for (string s : v) {

        if (find(s.begin(), s.end(), '.') == s.end()) {
            s += ".0";
        }

        while (!nine(s)) {
            s += "0";
        }

        ll a = 0;
        for (char c : s) {
            if (c == '.') continue;
            ll i = c - '0';
            a *= 10;
            a += i;
        }
        res.push_back(a);
    }
    return res;
}

vector<ll> sp(vector<ll> v, ll s) {
    vector<ll> res;
    for (ll l : v) {
        int ans = 0;
        while (l % s == 0) {
            ans++;
            l /= s;
        }
        res.push_back(ans);
    }
    return res;
}

// 2と5の両方が足して18になる組み合わせ
//

int main() {
    int n;
    cin >> n;
    vector<string> v(n);
    rep(i, n) cin >> v[i];

    vector<ll> v2 = up(v);

    vector<ll> tows = sp(v2, 2);
    vector<ll> fives = sp(v2, 5);

    ll ans = 0;
    rep(i, n) {
        rep(j, n) {
            if (tows[i] + tows[j] >= 18 && fives[i] + fives[j] >= 18) {
                ans++;
            }
        }
    }

    rep(i, n) {
        if (tows[i] + tows[i] >= 18 && fives[i] + fives[i] >= 18) {
            ans--;
        }
    }
    ans /= 2;

    cout << ans << endl;

}
