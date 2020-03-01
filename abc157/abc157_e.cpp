#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
//using namespace boost::multiprecision;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
const ll INF = 1e15;
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


struct SegTreeMax {
    ll N, dat[5 * 500000];

    SegTreeMax(ll n) {
        N = 1;
        while (N < n) N *= 2;
        for (ll i = 0; i < 2 * N - 1; i++)
            dat[i] = -INF;
    }

    // update k th element
    void update(ll k, ll a) {
        k += N - 1; // leaf
        dat[k] = a;
        while (k > 0) {
            k = (k - 1) / 2;
            dat[k] = max(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }

    // max [a, b)
    ll query(ll a, ll b) { return query(a, b, 0, 0, N); }

    ll query(ll a, ll b, ll k, ll l, ll r) {
        if (r <= a or b <= l) return -INF;
        if (a <= l and r <= b) return dat[k];
        ll m = (l + r) / 2;
        return max(query(a, b, k * 2 + 1, l, m), query(a, b, k * 2 + 2, m, r));
    }
};

int main() {

    int n, q;
    string s;
    cin >> n >> s >> q;

    vector<SegTreeMax> segs(26, SegTreeMax(n));

    rep(i, 26) {
        rep(j, n) {
            segs[i].update(j, 0);
        }
    }

    rep(i, q) {
        char c = s[i];
        segs[c - 'a'].update(i, 1);
    }

    rep(i, q) {
        int method;
        cin >> method;
        if (method == 1) {
            int j;
            char c;
            cin >> j >> c;
            j--;

            rep(k, 26) {
                segs[k].update(j, 0);
            }
            segs[c - 'a'].update(j, 1);

        } else {
            int l, r;
            cin >> l >> r;
            l--;
            int ans = 0;
            rep(k, 26) {
                int now = segs[k].query(l, r);
                assert(now == 1 || now == 0);
                ans += now;
            }
            cout << ans << endl;
        }
    }
}
