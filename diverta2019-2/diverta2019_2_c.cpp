#include <bits/stdc++.h>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

std::istream &operator>>(std::istream &in, set<ll> &o) {
    ll a;
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

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//const ll mod = 1e10;
//typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;


int main() {
    int n;
    cin >> n;
    vector<ll> v(n);
    rep(i, n) cin >> v[i];

    vector<ll> plus, minus;
    for (ll l : v)
        if (l < 0) minus.push_back(l);
        else plus.push_back(l);

    sort(plus.rbegin(), plus.rend());
    sort(minus.begin(), minus.end());

    if (plus.empty()) plus.push_back(minus.back()), minus.pop_back();
    if (minus.empty()) minus.push_back(plus.back()), plus.pop_back();

    vector<P> ans;


    while (plus.size() > 1) {
        ll m = minus.back();
        minus.pop_back();
        ll p = plus.back();
        plus.pop_back();

        ll next = m - p;
        assert(next <= 0);
        minus.push_back(next);

        ans.push_back({m, p});
    }

    while (minus.size() > 1) {
        ll m = minus.back();
        minus.pop_back();
        ll p = plus.back();
        plus.pop_back();

        ll next = p - m;
        assert(next >= 0);
        plus.push_back(next);

        ans.push_back({p, m});
    }

    ans.push_back({plus.back(), minus.back()});

    cout << ans.back().first - ans.back().second << endl;

    for (P p : ans) printf("%lld %lld\n", p.first, p.second);

}