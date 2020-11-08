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

bool equal(double a, double b) {
//    return fabs(a - b) < DBL_EPSILON;
    return fabs(a - b) < EPS;
}

template<class T>
std::istream &operator>>(std::istream &in, set<T> &o) {
    T a;
    in >> a;
    o.insert(a);
    return in;
}

template<class T>
std::istream &operator>>(std::istream &in, queue<T> &o) {
    ll a;
    in >> a;
    o.push(a);
    return in;
}

template<class T>
bool contain(set<T> &s, T a) { return s.find(a) != s.end(); }

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

int main() {
    string s;
    cin >> s;

    vector<int> count(3, 0);

    for (char c : s) {
        int i = c - '0';
        count[i % 3]++;
    }


    int ans = INT_MAX;

    auto check = [&](vector<int> tmp) -> bool {
        if (tmp == vector<int>{0, 0, 0}) return false;
        if (tmp[1] < 0 || tmp[2] < 0) return false;
        return (tmp[1] + (tmp[2] * 2)) % 3 == 0;
    };

    rep(i, 100) {
        rep(j, 100) {
            vector<int> tmp = count;
            tmp[1] -= i;
            tmp[2] -= j;

            bool ok = check(tmp);
            if (ok) {
                int now = i + j;
                cmin(ans, now);
            }
        }
    }

    if (ans == INT_MAX) ans = -1;

    cout << ans << endl;

}
