#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = 10e10;
const ll MINF = -10e10;
//const int INF = INT_MAX;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)

typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;
const int mod = 1000000007;
//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;

int comp(ll i, ll j) {
    if (i > j) {
        return -1;
    } else if (i == j) {
        return 1;
    } else {
        return 1;
    }
}
// https://atcoder.jp/contests/abc107/submissions/8719924
// 転倒数の数え方が理解できなかったのでお借りした。

// Binary Indexed Tree モジュール (0-indexed)
template<typename T>
class BIT {
private:
    vector<T> val;
public:
    ll n;

    BIT(ll _n) : val(_n + 1, 0), n(_n) {}

    BIT(vector<T> arr) : val(arr.size() + 1, 0), n(arr.size()) {
        rep(i, n) add(i, arr[i]);
    }

    // a[i] に v を足す O(logN)
    void add(const ll _i, const T _v) {
        for (ll i = _i + 1; i <= n; i += i & (-i)) {
            val[i] += _v;
        }
    }

    // [0, _i) の和を求める O(logN)
    T get(ll i) const {
        T ans = 0;
        for (; i > 0; i ^= i & (-i)) {
            ans += val[i];
        }
        return ans;
    }

    // [l, r) の和を求める o(N)
    T sum(const ll l, const ll r) {
        return get(r) - get(l);
    }
};

size_t inversion(vector<ll> &x0) {

    vector<ll> x = x0;
    const int n = x0.size();

    // 座圧
    vector<ll> unq = x;
    sort(unq.begin(), unq.end());
    unq.erase(unique(unq.begin(), unq.end()), unq.end());
    map<ll, int> sahz;
    for (size_t i = 0; i < unq.size(); i++) sahz[unq[i]] = i;
    for (size_t i = 0; i < x.size(); i++) x[i] = sahz[x[i]];

    // BITで転倒数を求める
    size_t ans = 0;
    BIT<int> bit(n);
    for (int i = 0; i < n; i++) {
        ans += bit.sum(x[i] + 1, n);
        bit.add(x[i], 1);
    }

    return ans;

}


int main() {
    ll n;
    cin >> n;

    vector<ll> as(n);
    rep(i, n) cin >> as[i];

    ll max_a = -1;
    ll min_a = INF;
    rep(i, n) max_a = max(max_a, as[i]);
    rep(i, n) min_a = min(min_a, as[i]);

    vector<ll> u_or_d(n);
    vector<ll> ruisekiwa(n);

    ll cell = max_a + 1;
    ll floor = min_a;
    while (floor + 1 < cell) {
        ll mid = (cell + floor) / 2;

        rep(j, n) u_or_d[j] = comp(mid, as[j]);

        ruisekiwa[0] = u_or_d[0];
        for (int i = 1; i < n; i++) {
            ruisekiwa[i] = ruisekiwa[i - 1] + u_or_d[i];
        }

        bool check = inversion(ruisekiwa) >= 0;

        if (!check) {
            cell = mid;
        } else {
            floor = mid;
        }
    }
    cout << floor << endl;


}