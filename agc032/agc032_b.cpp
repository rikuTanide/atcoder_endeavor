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
    cin >> n;

    int target = n % 2 == 0 ? n + 1 : n;

    vector<P> ans;

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (i + j == target) continue;
            else ans.push_back({i, j});
        }
    }


    cout << ans.size() << endl;
    for (P p : ans) printf("%lld %lld\n", p.first, p.second);

    ret();
    auto search = [](int n) {
        vector<P> v;
        rep(i, n) {
            rep(j, n) {
                if (i <= j) continue;
                v.push_back({i, j});
            }
        }

        int s = v.size();
        rep(i, 1ll << s) {
            UnionFind uf(n);
            vector<P> use;
            rep(j, s) if ((i >> j) & 1) {
                    uf.connect(v[j].first, v[j].second);
                    use.push_back(v[j]);
                }
            if (uf.size(0) < n) continue;


            vector<int> sum(n);
            for (P p : use) {
                sum[p.first] += p.second + 1;
                sum[p.second] += p.first + 1;
            }

            int mi = *min_element(sum.begin(), sum.end());
            int ma = *max_element(sum.begin(), sum.end());

            if (mi == ma) {
                cout << n << ' ' << mi << endl;
                for (P p : use) {
                    printf(" %lld %lld\n", p.first + 1, p.second + 1);
                }
            }
        }

    };

    for (int n = 3; n <= 7; n++) {
        search(n);
    }


}
