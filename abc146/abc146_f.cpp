#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
using namespace std;
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

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
const int mod = 1000000007;
//const ll mod = 1e10;
typedef priority_queue<string, vector<string>, greater<string> > PQ_ASK;

#include <iostream>
#include <vector>

using namespace std;

struct Food {
    ll time, good;
};

struct SegTreeMin {
    ll N, dat[4 * 100000];

    SegTreeMin() {}

    SegTreeMin(ll n) {
        N = 1;
        while (N < n) N *= 2;
        for (ll i = 0; i < 2 * N - 1; i++)
            dat[i] = INF;
    }

    // update k th element
    void update(ll k, ll a) {
        k += N - 1; // leaf
        dat[k] = a;
        while (k > 0) {
            k = (k - 1) / 2;
            dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }

    // min [a, b)
    ll query(ll a, ll b) { return query(a, b, 0, 0, N); }

    ll query(ll a, ll b, ll k, ll l, ll r) {
        if (r <= a or b <= l) return INF;
        if (a <= l and r <= b) return dat[k];
        ll m = (l + r) / 2;
        return min(query(a, b, k * 2 + 1, l, m), query(a, b, k * 2 + 2, m, r));
    }
};

int main() {
    int n, m;
    string s;

    cin >> n >> m >> s;
    SegTreeMin st(n + 1);
    rep(i, n + 2) st.update(i, INF);
    st.update(n, 0);

    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '1') {
            continue;
        }
        ll start = i + 1;
        ll end = min(i + m + 1, n + 1);
        ll mi = st.query(start, end);
        if (mi == INF) {
            cout << -1 << endl;
            ret();
        }
        st.update(i, mi + 1);
    }
    ll ma = st.query(0, 1);
    vector<ll> shortness(n + 1);
    rep(i, n + 2) shortness[i] = st.query(i, i + 1);

    vector<ll> points(ma + 1);
    for (ll i = n; i >= 0; i--) {
        ll p = shortness[i];
        if (p == INF) continue;
        points[p] = i;
    }
    reverse(points.begin(), points.end());
    rep(i, ma) {
        cout << points[i + 1] - points[i] << ' ';
    }
    cout << endl;
}