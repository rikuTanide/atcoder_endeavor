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

int main() {
    int n;
    cin >> n;

    vector<string> ss(n);
    rep(i, n) cin >> ss[i];

    {
        int now = 0;
        for (string &s: ss) {
            for (char c : s) {
                if (c == '(') now++;
                else now--;
            }
        }
        if (now != 0) {
            cout << "No" << endl;
            ret();
        }
    }

    vector<string> up, down;

    auto is_up = [&](string &s) -> bool {
        int now = 0;
        for (char c : s) {
            if (c == '(') now++;
            else now--;
        }
        return now >= 0;
    };

    for (string &s:ss) if (is_up(s)) up.push_back(s); else down.push_back(s);

    struct Index {
        int index, low;
    };

    auto calc_up_low = [&](string &s) -> int {
        int now = 0;
        int mi = 0;

        for (char c : s) {
            if (c == '(') now++;
            else now--;
            cmin(mi, now);
        }
        return mi;
    };

    auto calc_down_low = [&](string &s) -> int {
        int now = 0;
        int mi = 0;

        for (int i = s.size() - 1; i >= 0; i--) {
            char c = s[i];
            if (c == ')') now++;
            else now--;
            cmin(mi, now);
        }
        return mi;
    };

    vector<Index> up_indexes, down_indexes;
    rep(i, up.size()) up_indexes.push_back({i, calc_up_low(up[i])});
    rep(i, down.size()) down_indexes.push_back({i, calc_down_low(down[i])});

    sort(up_indexes.begin(), up_indexes.end(), [](Index i1, Index i2) { return i1.low > i2.low; });
    sort(down_indexes.begin(), down_indexes.end(), [](Index i1, Index i2) { return i1.low < i2.low; });

    vector<string> tmp;
    for (Index i: up_indexes) tmp.push_back(up[i.index]);
    for (Index i: down_indexes)tmp.push_back(down[i.index]);

    auto check = [](vector<string> &v) -> bool {
        int now = 0;
        int mi = 0;
        for (string &s: v) {
            for (char c : s) {
                if (c == '(') now++;
                else now--;
                cmin(mi, now);
            }
        }
        return mi >= 0;
    };

    bool ok = check(tmp);
    cout << (ok ? "Yes" : "No") << endl;

}
