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

struct Q {
    char c, d;
};

int main() {
    int n, q;
    string s;
    cin >> n >> q >> s;

    vector<Q> queries(q);
    for (Q &query : queries) cin >> query.c >> query.d;


    auto check_l = [&](int i) -> bool {
        int now = i;
        for (Q query : queries) {
            if (s[now] == query.c) {
                if (query.d == 'L') now--;
                else now++;
            }
            if(now == n) return true;
            if (now == -1) return false;
        }
        return true;
    };

    auto check_r = [&](int i) -> bool {
        int now = i;
        for (Q query : queries) {
            if (s[now] == query.c) {
                if (query.d == 'L') now--;
                else now++;
            }
            if (now == n) return false;
            if(now == -1) return true;
        }
        return true;
    };

    if (!check_r(0) || !check_l(n - 1)) {
        cout << 0 << endl;
        ret();
    }

    auto find_l = [&]() -> int {
        int floor = 0, ceil = n;
        while (floor + 1 < ceil) {
            int mid = (floor + ceil) / 2;
            bool ok = check_l(mid);
            if (!ok) floor = mid;
            else ceil = mid;
        }
        return ceil;
    };

    auto find_r = [&]() -> int {
        int floor = 0, ceil = n;
        while (floor + 1 < ceil) {
            int mid = (floor + ceil) / 2;
            bool ok = check_r(mid);
            if (ok) floor = mid;
            else ceil = mid;
        }
        return floor;
    };

    int l = find_l();
    int r = find_r();

    int ans = r - l + 1;
    cout << ans << endl;

}
