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
    string s;
    cin >> s;
    int n = s.size();
    vector<int> j_seq(n, -1), o_seq(n, -1), i_seq(n, -1);

    auto get_si = [&](int i) -> char {
        if (i < 0) return '*';
        if (i >= n) return '*';
        return s[i];
    };

    auto get_vi = [&](vector<int> &v, int i) -> int {
        if (i < 0) return -1;
        if (i >= n) return -1;
        return v[i];
    };

    for (int i = 0; i < n; i++) {
        if (get_si(i - 1) == 'J' && get_si(i) == 'J') {
            j_seq[i] = get_vi(j_seq, i - 1) + 1;
        } else if (get_si(i) == 'J') {
            j_seq[i] = 1;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (get_si(i) == 'O') {
            if (get_si(i + 1) == 'O') {
                o_seq[i] = get_vi(o_seq, i + 1) + 1;
            } else {
                o_seq[i] = 1;
            }
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (get_si(i) == 'I') {
            if (get_si(i + 1) == 'I') {
                i_seq[i] = get_vi(i_seq, i + 1) + 1;
            } else {
                i_seq[i] = 1;
            }
        }
    }
    int ans = 0;
    rep(i, n) {
        if (get_si(i) != 'O') {
            continue;
        }

        int j_len = get_vi(j_seq, i - 1);
        int o_len = get_vi(o_seq, i);
        int i_len = get_vi(i_seq, i + o_len);

        if (j_len >= o_len && o_len <= i_len) {
            cmax(ans, o_len);
        }
    }


    cout << ans << endl;


}
