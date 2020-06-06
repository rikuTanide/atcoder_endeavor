#include <bits/stdc++.h>

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

//const ll mod = 1e10;
typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;

// https://algo-logic.info/binary-indexed-tree/
template<typename T>
struct BIT {
    int n;             // 要素数
    vector<T> bit[2];  // データの格納先
    BIT(int n_) { init(n_); }

    void init(int n_) {
        n = n_ + 1;
        for (int p = 0; p < 2; p++) bit[p].assign(n, 0);
    }

    void add_sub(int p, int i, T x) {
        for (int idx = i; idx < n; idx += (idx & -idx)) {
            bit[p][idx] += x;
        }
    }

    void add(int l, int r, T x) {  // [l,r) に加算
        add_sub(0, l, -x * (l - 1));
        add_sub(0, r, x * (r - 1));
        add_sub(1, l, x);
        add_sub(1, r, -x);
    }

    T sum_sub(int p, int i) {
        T s(0);
        for (int idx = i; idx > 0; idx -= (idx & -idx)) {
            s += bit[p][idx];
        }
        return s;
    }

    T sum(int i) { return sum_sub(0, i) + sum_sub(1, i) * i; }
};

int main() {

    int n, m;
    cin >> n >> m;

    vector<P> v(n);
    for (P &p : v) cin >> p.first >> p.second;

    // 小さい順
    // 含むを減らしていく
    // 飛ぶを増やしていく

    map<int, vector<P>> g;
    for (P p : v) g[p.second - p.first + 1].push_back(p);

    int a = n;

    BIT<ll> bit(m + 2);


    for (int k = 1; k <= m; k++) {

        a -= g[k - 1].size();

        for (P p : g[k - 1]) {
            bit.add(p.first, p.second + 1, 1);
        }


        int b = 0;

        for (int j = 0; j <= m; j += k) {
            b += bit.sum(j) - bit.sum(j - 1);
        }

        cout << a + b << endl;

    }

}
