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
const int mod = 1000000007;

bool can(int l, int i, int t, vector<ll> &numbers) {
    vector<int> v(l, 0);
    rep(k, l) v[k] = ((numbers[k] >> i) & 1);
    vector<int> s(l);
    s[0] = t;
    rep(k, l - 1) s[k + 1] = v[k] ^ s[k];
    return (s[l - 1] ^ v[l - 1]) == s[0];
}

int main() {
    int l;
    cin >> l;
    vector<ll> numbers(l);
    rep(i, l) cin >> numbers[i];

    ll first = 0;
    rep(i, 32) {
        if (can(l, i, 0, numbers)) {
            continue;
        } else if (can(l, i, 1, numbers)) {
            first += (1ll << i);
        } else {
            cout << -1 << endl;
            ret();
        }
    }
    vector<ll> ans(l);
    ans[0] = first;

    rep(k, l - 1) ans[k + 1] = numbers[k] ^ ans[k];

    for(ll l : ans) cout << l<<endl;

}

