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

std::istream &operator>>(std::istream &in, set<int> &o) {
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

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

ll f(ll k) {
    return k * (k + 1) / 2;
}

int main() {

    ll n, c;
    cin >> n >> c;

    vector<ll> numbers(n);
    rep(i, n) cin >> numbers[i];
    vector<vector<ll>> v(c + 1);
    rep(i, n) v[numbers[i]].push_back(i);

    ll all = f(n);

    rep(i, c + 1) {
        if (i == 0)continue;
        ll s = f(v[i].front());
        ll e = f(n - 1 - v[i].back());

        ll ts = 0;
        rep(j, v[i].size() - 1) {
            ll x = v[i][j];
            ll y = v[i][j + 1];

            ll t = f(y - x - 1);
            ts += t;
        }

        ll sum = s + e + ts;
        ll now = all - sum;
        cout << now <<endl;
    }

}

