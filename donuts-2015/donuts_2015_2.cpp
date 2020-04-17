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

ll get_idol_points(int i, vector<ll> &idols, int n) {
    ll sum = 0;
    rep(j, n) {
        if ((i >> j) & 1) sum += idols[j];
    }
    return sum;
}

bool is_all_member(set<int> &s, int i, int n) {
    int c = 0;
    for (ll j : s) {
        if ((i >> j) & 1) c++;
    }
    return c >= 3;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> idols(n);
    rep(i, n)cin >> idols[i];
    vector<set<int>> comb(m);
    vector<ll> bonus(m);
    rep(i, m) {
        cin >> bonus[i];
        int c;
        cin >> c;
        rep(j, c) {
            int k;
            cin >> k;
            k--;
            comb[i].insert(k);
        }
    }

//    int i = 0b111110011011;
//    for (auto s : comb) {
//        cout << is_all_member(s, i, n) << endl;
//    }
//
//    return 0;
    ll ans = 0;
    for (int i = 0; i < (1 << n); i++) {
        if (__builtin_popcount(i) != 9) continue;
        ll idol_points = get_idol_points(i, idols, n);
        ll bonus_sum = 0;
        rep(j, m) {
            set<int> &s = comb[j];
            if (is_all_member(s, i, n)) bonus_sum += bonus[j];
        }
        ll sum = idol_points + bonus_sum;
        cmax(ans, sum);
    }
    cout << ans << endl;
}

