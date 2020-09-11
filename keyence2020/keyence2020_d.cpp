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

int calc(vector<int> e, vector<int> o) {
    vector<P> ep, op;
    rep(i, e.size()) ep.push_back({e[i], -1});
    rep(i, o.size()) op.push_back({o[i], -1});

    vector<int> tmp;
    for (int i : e) tmp.push_back(i);
    for (int i : o) tmp.push_back(i);
    sort(tmp.begin(), tmp.end());

    rep(i, tmp.size()) {
        if (i % 2 == 0) {
            rep(j, ep.size()) {
                if (ep[j].first == tmp[i] && ep[j].second == -1) {
                    ep[j].second = i;
                    break;
                }
            }
        } else {
            rep(j, op.size()) {
                if (op[j].first == tmp[i] && op[j].second == -1) {
                    op[j].second = i;
                    break;
                }
            }
        }
    }
    vector<int> rank;
    rep(i, ep.size()) {
        rank.push_back(ep[i].second);
        if (op.size() > i) rank.push_back(op[i].second);
    }
    int n = rank.size();
    int ans = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (rank[j] > rank[i]) ans++;
        }
    }
    return ans;
}


int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    int ans = INT_MAX;
    rep(i, 1 << n) {

        vector<int> e, o;
        vector<vector<int>> tmp;

        rep(j, n) {

            if (j % 2 == 0) {
                if ((i >> j) & 1) {
                    o.push_back(b[j]);
                } else {
                    e.push_back(a[j]);
                }
            } else {
                if ((i >> j) & 1) {
                    e.push_back(b[j]);
                } else {
                    o.push_back(a[j]);
                }
            }
        }

        bool ok = is_enable(n, e, o);
        if (!ok) continue;
        int cost = calc(e, o);
        cmin(ans, cost);
    }
    ans = ans == INT_MAX ? -1 : ans;
    cout << ans << endl;
}
