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


struct Rail {
    int a, b, l;
};

std::istream &operator>>(std::istream &in, Rail &o) {
    in >> o.a >> o.b >> o.l;
    return in;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Rail> rails(m);
    rep(i, m) cin >> rails[i];

    map<int, map<int, ll>> mp;


    for (Rail r : rails) {
        mp[r.a][r.l]++;
        mp[r.b][r.l]++;
    }
    ll ans = 0;
    const int K = 2540;
    for (int i = 1; i <= n; i++) {
        for (auto e : mp[i]) {
            ll j = e.first;
            ll c = e.second;

            if (j < (K / 2)) {
                ans += (c * mp[i][K - j]);
            } else if (j == (K / 2)) {
                ans += (c * (c - 1) / 2);
            }

        }
    }
    cout << ans << endl;


}