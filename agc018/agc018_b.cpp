#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
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

typedef pair<ll, ll> P;

struct Res {
    ll remove_sport, max_count;
};

Res f(vector<vector<int>> &sports, set<int> &close, int n, int m) {

    map<int, int> ma;
    rep(i, n) {
        vector<P> candidate;
        rep(j, m) if (close.find(j) == close.end()) candidate.push_back(P(sports[i][j], j));
        P p = *min_element(candidate.begin(), candidate.end());
        ma[p.second]++;
    }

    int ma_c = 0;
    for (auto &e : ma) cmax(ma_c, e.second);
    for (auto &e : ma) if (e.second == ma_c) return Res{e.first, e.second};
    __throw_runtime_error("");
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> spots(n, vector<int>(m));
    rep(i, n) rep(j, m) {
            int s;
            cin >> s;
            s--;
            spots[i][s] = j;
        }

    set<int> close;
    ll ans = INF;
    rep(i, m - 1) {
        Res r = f(spots, close, n, m);
        cmin(ans, r.max_count);
        close.insert(r.remove_sport);
    }
    cout << ans << endl;

}
