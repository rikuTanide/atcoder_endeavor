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

class Points {

    multiset<ll> s;
public:
    void push(P p) {
        s.insert(p.second);
    }

    void pop(P p) {
        s.erase(s.find(p.second));
    }

    ll max() {
        if (s.empty()) return -INF;
        auto it = s.end();
        it--;
        return *it;
    }

    ll min() {
        if (s.empty()) return INF;
        return *s.begin();
    }

};

ll manhattan(vector<P> &p) {
    int n = p.size();
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            P a = p[i];
            P b = p[j];
            ll now = abs(a.first - b.first) + abs(a.second - b.second);
            cmax(ans, now);
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
//    n = 100;
    vector<P> v(n);
    for (P &p:v) cin >> p.first >> p.second;
//    vector<P> v;
//    rep(i, 10) rep(j, 10) v.push_back({i, j});

    sort(v.begin(), v.end(), [](P p1, P p2) {
        if (p1.first != p2.first) return p1.first < p2.first;
        return p1.second > p2.second;
    });

    vector<P> candidate1;
    {
        Points left1, right1;

        for (P p : v) right1.push(p);
        for (P p : v) {
            right1.pop(p);
            if (left1.max() >= p.second && p.second >= right1.min()) {
            } else {
                candidate1.push_back(p);
            }
            left1.push(p);
        }
    }
    sort(candidate1.begin(), candidate1.end(), [](P p1, P p2) {
        if (p1.first != p2.first) return p1.first < p2.first;
        return p1.second < p2.second;
    });

    vector<P> candidate2;
    {
        Points left2, right2;
        for (P p : candidate1) right2.push(p);
        for (P p : candidate1) {
            right2.pop(p);
            if (left2.min() <= p.second && p.second <= right2.max()) {
            } else {
                candidate2.push_back(p);
            }
            left2.push(p);
        }
    }

    ll ans = manhattan(candidate2);
    cout << ans << endl;
}
