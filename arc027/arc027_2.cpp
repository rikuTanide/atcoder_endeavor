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

class UnionFind {
public:
    // 親の番号を格納する。親だった場合-size
    vector<int> parents;

    UnionFind(int n) {
        parents = vector<int>(n, -1);
    }

    // aがどのグループに属しているか
    int root(int a) {
        if (parents[a] < 0) {
            return a;
        }
        return parents[a] = root(parents[a]);
    }

    int size(int a) {
        return -parents[root(a)];
    }

    // aとbをくっつける
    bool connect(int a, int b) {
        int ra = root(a);
        int rb = root(b);
        if (ra == rb) {
            return false;
        }
        // 大きいほうにA
        if (size(ra) < size(rb)) {
            swap(ra, rb);
        }
        parents[ra] += parents[rb];
        parents[rb] = ra;
        return true;
    }

    bool is_union(int a, int b) {
        int ra = root(a);
        int rb = root(b);
        return ra == rb;
    }
};

int main() {
    int n;
    string s, t;
    cin >> n >> s >> t;

    UnionFind uf(300);
    rep(i, n) {
        int a = s[i];
        int b = t[i];
        uf.connect(a, b);
    }

    auto is_num_union = [&](int i) {
        for (int j = 0; j <= 9; j++) {
            if (uf.is_union(i, '0' + j))return true;
        }
        return false;
    };

    set<int> use_chars;
    for (int i : s) use_chars.insert(i);
    for (int i : t) use_chars.insert(i);

    set<int> parents;
    for (int i : use_chars) parents.insert(uf.root(i));

    set<int> n_parents;
    for (int i : parents) if (!is_num_union(i)) n_parents.insert(i);

    ll ans = 1;
    for (int i : n_parents) if (uf.is_union(i, s[0]) || uf.is_union(i, t[0])) ans *= 9; else ans *= 10;

    cout << ans << endl;
}

