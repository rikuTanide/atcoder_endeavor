#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
typedef pair<ll, ll> P;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
const ll INF = 10e14;
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

struct Book {
    int value;
    vector<int> skills;
};

int main() {
    int n, m, x;
    cin >> n >> m >> x;

    vector<Book> books(n);
    rep(i, n) {

        int value;
        cin >> value;

        books[i].value = value;
        books[i].skills = vector<int>(m);

        rep(j, m) {
            cin >> books[i].skills[j];
        }

    }
    ll ans = INF;
    rep(i, 1 << n) {
        vector<int> tmp(m);
        ll sum = 0;
        rep(j, n) {
            if (!((i >> j) & 1))continue;
            Book b = books[j];
            sum += b.value;

            rep(k, m) tmp[k] += b.skills[k];
        }
        ll mi = *min_element(tmp.begin(), tmp.end());
        if (mi < x) continue;
        cmin(ans, sum);
    }
    if (ans == INF) {
        cout << -1 << endl;
        ret();
    }
    cout << ans << endl;
}



