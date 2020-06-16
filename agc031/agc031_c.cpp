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

int bpc(int i) {
    return __builtin_popcount(i) % 2;
}

bool bit(int n, int i) {
    return (n >> i) & 1;
}

int search_x(int a, int b) {
    rep(i, 32) {
        if (bit(a, i) != bit(b, i)) return i;
    }
    __throw_runtime_error("konaidene");
}


vector<int> rec(vector<int> &v, set<int> &old_x, int a, int b) {
    assert(bpc(a) != bpc(b));
    assert(find(v.begin(), v.end(), a) != v.end());
    assert(find(v.begin(), v.end(), b) != v.end());

    if (v.size() == 2) return {a, b};

    int x = search_x(a, b);
    old_x.insert(x);

    vector<int> u1, u2;
    u1.push_back(a);
    for (int i : v) {
        if (i == a || i == b) continue;
        if (bit(i, x) == bit(a, x)) u1.push_back(i); else u2.push_back(i);
    }
    u2.push_back(b);

    {
        for (ll l : u1) assert(bit(l, x) == bit(a, x));
        for (ll l : u2) assert(bit(l, x) == bit(b, x));
    }

    assert(u1.size() == u2.size());

    P p = [&] {
        for (int l1 : u1) {
            if (l1 == a) continue;
            if (bpc(a) == bpc(l1))continue;

            for (int l2 : u2) {
                if (l2 == b) continue;
                if (bpc(l2) == bpc(b))continue;
                int xx = 1 << x;

                assert(bit(l1, x) != bit(l2, x));

                if ((l1 | xx) == (l2 | xx)) {
                    return P(l1, l2);
                }
            }
        }
        __throw_runtime_error("konaide");
    }();

    auto t1 = rec(u1, old_x, a, p.first), t2 = rec(u2, old_x, p.second, b);
    for (int k : t2) t1.push_back(k);
    old_x.erase(x);
    return t1;

}

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    if (bpc(a) % 2 == bpc(b) % 2) {
        cout << "NO" << endl;
        ret();
    }

    cout << "YES" << endl;

    vector<int> v(1 << n);
    rep(i, 1 << n) v[i] = i;

    set<int> old_x;
    auto ans = rec(v, old_x, a, b);

    for (int i : ans) cout << i << ' ';
    cout << endl;

}
