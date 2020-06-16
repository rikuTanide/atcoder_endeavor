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
    return __builtin_popcount(i);
}

vector<int> search_x(int a, int b) {
    vector<int> ans;
    rep(i, 32) {
        if (a % 2 != b % 2) ans.push_back(i);
        a /= 2;
        b /= 2;
    }
    assert(!ans.empty());
    return ans;
}

bool bit(int n, int i) {
    return (n >> i) & 1;
}

vector<int> rec(vector<int> &v, int a, int b) {
    assert(find(v.begin(), v.end(), a) != v.end());
    assert(find(v.begin(), v.end(), b) != v.end());

    if (v.size() == 2) return {a, b};

    vector<int> xs = search_x(a, b);
    for (int x : xs) {
        vector<int> u1, u2;
        u1.push_back(a);
        for (int i : v) {
            if (i == a || i == b) continue;
            if (bit(i, x) == bit(a, x)) u1.push_back(i); else u2.push_back(i);
        }
        u2.push_back(b);

        assert(u1.size() == u2.size());

        P p = [&] {
            for (int l1 : u1) {
                if (l1 == a) continue;
                for (int l2 : u2) {
                    if (l2 == b) continue;
                    int xx = 1 << x;
                    if ((l1 | xx) == (l2 | xx)) {
                        return P(l1, l2);
                    }
                }
            }
            return P(-1, -1);
        }();
        if (p == P(-1, -1)) {
            continue;
        }

        auto t1 = rec(u1, a, p.first), t2 = rec(u2, p.second, b);
        if (t1.empty() || t2.empty()) continue;
        for (int k : t2) t1.push_back(k);
        return t1;
    }
    return {};
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
    auto ans = rec(v, a, b);

    for (int i : ans) cout << i << ' ';
    cout << endl;

}
