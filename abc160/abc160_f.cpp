#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;
//#include "atcoder/all"

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
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

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;
const int mod = 1000000007;

struct mint {
    ll x; // typedef long long ll;
    mint(ll x = 0) : x((x % mod + mod) % mod) {}

    mint &operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }

    mint &operator-=(const mint a) {
        if ((x += mod - a.x) >= mod) x -= mod;
        return *this;
    }

    mint &operator*=(const mint a) {
        (x *= a.x) %= mod;
        return *this;
    }

    mint operator+(const mint a) const {
        mint res(*this);
        return res += a;
    }

    mint operator-(const mint a) const {
        mint res(*this);
        return res -= a;
    }

    mint operator*(const mint a) const {
        mint res(*this);
        return res *= a;
    }

    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1) a *= *this;
        return a;
    }

    // for prime mod
    mint inv() const {
        return pow(mod - 2);
    }

    mint &operator/=(const mint a) {
        return (*this) *= a.inv();
    }

    mint operator/(const mint a) const {
        mint res(*this);
        return res /= a;
    }

    friend std::istream &operator>>(std::istream &in, mint &o) {
        ll a;
        in >> a;
        o = a;
        return in;
    }

    friend std::ostream &operator<<(std::ostream &out, const mint &o) {
        out << o.x;
        return out;
    }

};

struct Triangle {
    int parent;
    vector<int> children;
};

class Tree {
    vector<vector<int>> edges;
public:
    Tree(int n) : edges(n) {}

    void edge(int i, int j) {
        edges[i].push_back(j);
        edges[j].push_back(i);
    }

    vector<Triangle> root(int r) {
        vector<Triangle> leafs;

        queue<int> vs;
        vs.push(r);
        vector<bool> check(edges.size(), false);
        check[r] = true;
        while (!vs.empty()) {
            int k = vs.front();
            Triangle triangle;
            triangle.parent = k;

            for (int i : edges[k]) {
                if (check[i]) continue;
                check[i] = true;
                triangle.children.push_back(i);
                vs.push(i);
            }
            vs.pop();
            leafs.push_back(triangle);
        }

        reverse(leafs.begin(), leafs.end());
        return leafs;
    }
};

struct combination {
    vector<mint> fact, ifact;

    combination(int n) : fact(n + 1), ifact(n + 1) {
        assert(n < mod);
        fact[0] = 1;
        for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i;
        ifact[n] = fact[n].inv();
        for (int i = n; i >= 1; --i) ifact[i - 1] = ifact[i] * i;
    }

    mint operator()(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact[n] * ifact[k] * ifact[n - k];
    }
} combination(1000000);

mint factor(int i) {
    return combination.fact[i];
}

int main() {
    int n;
    cin >> n;
    vector<P> v(n - 1);
    for (P &p:v) cin >> p.first >> p.second, p.first--, p.second--;

    Tree tree(n);
    for (P p : v) tree.edge(p.first, p.second);


    auto leafs = tree.root(0);

    vector<int> child_counts(n);
    for (Triangle &t : leafs) {

        int parent = t.parent;
        for (int child : t.children) {
            child_counts[parent] += child_counts[child];
            child_counts[parent]++;
        }

    }
    vector<mint> dp(n, 1);
    vector<mint> child_factor_muls(n);
    vector<mint> child_dp_muls(n);
    vector<int> parents(n, -1);

    for (Triangle &t : leafs) {
        int parent = t.parent;

        mint parent_factor = factor(child_counts[parent]);
        mint child_factor_mul = 1;
        mint child_dp_mul = 1;

        for (int child : t.children) {
            child_factor_mul *= factor(child_counts[child] + 1);
        }

        for (int child : t.children) {
            child_dp_mul *= dp[child];
        }

        for (int child: t.children) {
            parents[child] = t.parent;
        }

        child_factor_muls[parent] = child_factor_mul;
        child_dp_muls[parent] = child_dp_mul;
        mint now = parent_factor * child_dp_mul / child_factor_mul;
        dp[parent] = now;
    }
    vector<mint> ans(n);
    ans[0] = dp[0];

    reverse(leafs.begin(), leafs.end());

    auto calc_new_dp = [&](int prev_root, int new_root) -> mint {
        mint prev_root_factor_muls = child_factor_muls[prev_root];
        mint exclude_factor = factor(child_counts[new_root] + 1);
        mint factor_mul = prev_root_factor_muls / exclude_factor;
        mint dp_mul = child_dp_muls[prev_root] / dp[new_root];
        mint all_factor = factor(n - 2 - child_counts[new_root]);
        mint now = all_factor * dp_mul / factor_mul;
        return now;
    };

    auto calc_new_leaf_size = [&](int prev_root, int new_root) -> int {
        return n - 1 - child_counts[new_root];
    };

    auto move_root = [&](int new_root) {
        int prev_root = parents[new_root];
        if (prev_root == -1) return;
//        child_counts[new_root] = n - 1;
        mint next = calc_new_dp(prev_root, new_root);
        child_dp_muls[new_root] *= next;
        child_factor_muls[new_root] *= factor(calc_new_leaf_size(prev_root, new_root));

        mint dp_mul = child_dp_muls[new_root];
        mint factor_mul = child_factor_muls[new_root];

        mint now = factor(n - 1) * dp_mul / factor_mul;
        ans[new_root] = now;
        dp[new_root] = now;

    };

    for (Triangle &t: leafs) {
        move_root(t.parent);
    }

    for(mint a : ans) cout << a << endl;

}
