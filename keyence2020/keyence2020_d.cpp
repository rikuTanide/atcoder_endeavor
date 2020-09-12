#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

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

bool is_enable(int n, vector<int> e, vector<int> o) {

    if (!(e.size() == (n + 1) / 2)) return false;
    if (!(o.size() == n / 2)) return false;

    sort(e.begin(), e.end());
    sort(o.begin(), o.end());
    vector<int> tmp;
    rep(i, e.size()) {
        tmp.push_back(e[i]);
        if (o.size() > i) tmp.push_back(o[i]);
    }


    rep(i, tmp.size() - 1) {
        if (!(tmp[i] <= tmp[i + 1])) return false;
    }
    return true;

}

int calc(vector<P> v) {
    int n = v.size();

    vector<int> tmp;
    for (P p : v) tmp.push_back(p.first);
    sort(tmp.begin(), tmp.end());

    vector<int> rank(n, -1);
    rep(i, n) {
        rep(j, n) {
            if (
                    v[j].first == tmp[i] &&
                    i % 2 == v[j].second &&
                    rank[j] == -1
                    ) {
                rank[j] = i;
                break;
            }
        }
    }


    int ans = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (rank[j] > rank[i]) ans++;
        }
    }

    return ans;
}


int main() {
//    cout << bitset<15>(20259) << endl;
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    int ans = INT_MAX;
    rep(i, 1 << n) {

        vector<int> e, o;
        vector<P> tmp;

        rep(j, n) {

            if (j % 2 == 0) {
                if ((i >> j) & 1) {
                    o.push_back(b[j]);
                    tmp.push_back({b[j], 1});
                } else {
                    e.push_back(a[j]);
                    tmp.push_back({a[j], 0});
                }
            } else {
                if ((i >> j) & 1) {
                    e.push_back(b[j]);
                    tmp.push_back({b[j], 0});
                } else {
                    o.push_back(a[j]);
                    tmp.push_back({a[j], 1});
                }
            }
        }

        bool ok = is_enable(n, e, o);
        if (!ok) continue;
        int cost = calc(tmp);
        cmin(ans, cost);
    }
    ans = ans == INT_MAX ? -1 : ans;
    cout << ans << endl;
}