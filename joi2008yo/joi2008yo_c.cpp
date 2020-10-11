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

    set<int> hanako, taro;
    for (int i = 1; i <= 2 * n; i++) hanako.insert(i);

    rep(_, n) {
        int a;
        cin >> a;
        hanako.erase(a);
        taro.insert(a);
    }

    int stage = 0;
    char turn = 't';

    auto can = [&](set<int> &s) {
        return s.upper_bound(stage) != s.end();
    };

    auto put = [&](set<int> &s) {
        auto it = s.upper_bound(stage);
        assert(it != s.end());

        int a = *it;
        s.erase(it);
        return a;
    };

    while (true) {
        if (turn == 't') {
            if (can(taro)) {
                stage = put(taro);
            } else {
                stage = 0;
            }
        } else {
            if (can(hanako)) {
                stage = put(hanako);
            } else {
                stage = 0;
            }
        }
        if (taro.empty() || hanako.empty()) break;
        turn = turn == 't' ? 'h' : 't';
    }

    int taro_point = hanako.size(), hanako_point = taro.size();

    cout << taro_point << endl << hanako_point << endl;
}
