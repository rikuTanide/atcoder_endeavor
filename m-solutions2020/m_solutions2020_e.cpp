#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

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

struct Village {
    ll x, y, p;
};

std::istream &operator>>(std::istream &in, Village &o) {
    in >> o.x >> o.y >> o.p;
    return in;
}

ll check(int n, vector<Village> &villages, vector<char> &ptn) {
    vector<ll> v = {0}, h = {0};
    rep(i, n) {
        Village &village = villages[i];
        if (ptn[i] == 'e') continue;
        else if (ptn[i] == 'v') v.push_back(village.x);
        else if (ptn[i] == 'h') h.push_back(village.y);
    }
    ll ans = 0;
    rep(i, n) {
//    for (Village &village : villages) {
        if (ptn[i] != 'e') continue;
        Village &village = villages[i];
        ll now = INF;
//        for (ll x : v) {
//            cmin(now, abs(x - village.x));
//        }
//        for (ll y : h) {
//            cmin(now, abs(y - village.y));
//        }
        ans += (now * village.p);
    }
    return ans;

}

void rec(int n, int i, vector<Village> &villages, vector<char> &ptn, vector<ll> &anss) {
    if (i == n) {
        ll ans = check(n, villages, ptn);
        int t = n - count(ptn.begin(), ptn.end(), 'e');
        cmin(anss[t], ans);
        return;
    }

    ptn[i] = 'e';
    rec(n, i + 1, villages, ptn, anss);
    ptn[i] = 'h';
    rec(n, i + 1, villages, ptn, anss);
    ptn[i] = 'v';
    rec(n, i + 1, villages, ptn, anss);
}

int main() {

    cout << int(pow(3, 15)) << endl;
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Village> villages(n);
    rep(i, n) cin >> villages[i];
    vector<char> ptn(n, ' ');
    vector<ll> ans(n + 1, INF);
    rec(n, 0, villages, ptn, ans);

    for (ll l : ans) cout << l << '\n';


}
