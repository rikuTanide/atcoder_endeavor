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

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<string> &o) {
    string a;
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

vector<int> amida_simulator(vector<int> &horizontal, int width) {
    vector<int> currents(width);
    vector<int> current_indexes(width);
    rep(i, width) currents[i] = i;
    rep(i, width) current_indexes[i] = i;

    for (int h : horizontal) {
        int h1 = currents[h];
        int h2 = currents[h + 1];

        swap(current_indexes[h1], current_indexes[h2]);
        currents[h] = h2;
        currents[h + 1] = h1;

    }
    return current_indexes;
}

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


struct Amida {
    int n;
    vector<int> horizontal;
};

vector<Amida> split_amida(int n, int m, vector<int> &horizontal) {
    UnionFind uf(n);
    for (int i : horizontal) {
        uf.connect(i, i + 1);
    }

    map<int, vector<int>> vs;
    for (int i : horizontal) {
        int r = uf.root(i);
        vs[r].push_back(i);
    }

    vector<Amida> res;
    rep(i, n) {
        if (uf.root(i) != i) continue;
        Amida a = {uf.size(i), vs[i]};
        res.push_back(a);
    }
    return res;
}

ll get_cycle(Amida &amida) {
    int i = 1;
    vector<int> table = amida_simulator(amida.horizontal, amida.n);

    int now = table[0];
    while (now != 0) {
        now = table[now];
        i++;
    }

    return i;
}

void solve(Amida &amida, ll d) {
    vector<int> current(amida.n);
    rep(i, amida.n) current[i] = i;
    ll cycle = get_cycle(amida);
    d %= cycle;

    vector<int> table = amida_simulator(amida.horizontal, amida.n);

    rep(i, d) {
        vector<int> next(amida.n);
        rep(j, amida.n) {
            next[j] = current[table[j]];
        }
        current = next;
    }

    for (int i : current) cout << (i + 1) << endl;

}

int main() {
    int n, m;
    ll d;
    cin >> n >> m >> d;
    vector<int> horizontal(m);
    rep(i, m) cin >> horizontal[i];
    rep(i, m) horizontal[i]--;

    auto amidas = split_amida(n, m, horizontal);

    for (Amida &a : amidas) {
        solve(a, d);
    }


}
