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

const string atcoder = "atcoder";

ll find_right_equal(string &s, int start, char target) {
    for (int i = start; i < s.size(); i++) {
        if (s[i] == target) return i;
    }
    return INF;
}

ll find_right_upper(string &s, int start, char target) {
    for (int i = start; i < s.size(); i++) {
        if (s[i] > target) return i;
    }
    return INF;
}

string swap_range(string &s, int i, int j) {
    string ans;
    rep(t, i) ans.push_back(s[t]);
    ans.push_back(s[j]);
    for (int t = i; t < j; t++) ans.push_back(s[t]);
    for (int t = j + 1; t < s.size(); t++) ans.push_back(s[t]);
    return ans;
}

// atcoder　でチェック
ll solve(string &s, int i) {
    ll fre = find_right_equal(s, i + 1, atcoder[i]);
    ll fru = find_right_upper(s, i + 1, atcoder[i]);


    auto eq = [&]() -> ll {
        // 大きいのを持ってくる
        string next = swap_range(s, i, fre);
        ll now = solve(next, i + 1);
        if (now == INF) return INF;
        return fre - i + now;
    };

    auto up = [&]() -> ll {
        return fru - i;
    };

    if (s[i] < atcoder[i]) {
        if (fre == INF && fru == INF) {
            return INF;
        }
        if (fre == INF) {
            return up();
        }
        if (fru == INF) {
            return eq();
        }
        return min(up(), eq());
    } else if (s[i] == atcoder[i]) {
        ll sl = solve(s, i + 1);
        if (fru == INF) {
            return sl;
        }
        return min(sl, fru - i);
    } else {
        return 0;
    }

}

int main() {
    int n;
    cin >> n;


    rep(_, n) {

        string s;
        cin >> s;

        if (s == atcoder) {
            cout << 1 << endl;
            continue;
        }

        ll ans = solve(s, 0);
        cout << (ans == INF ? -1 : ans) << endl;


    }

}
