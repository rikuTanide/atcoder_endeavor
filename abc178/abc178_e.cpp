#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

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
//    for (P q : p) cout << q.first << ' ' << q.second << endl;
//    cout << endl;

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

//    for (int i = 0; i < n; i++) {
//        for (int j = i + 1; j < n; j++) {
//            P a = p[i];
//            P b = p[j];
//            ll now = abs(a.first - b.first) + abs(a.second - b.second);
//            if (now == ans) printf("[%lld %lld] [%lld %lld]\n", a.first, a.second, b.first, b.second);
//        }
//    }
//
    return ans;
}

ll solve(vector<P> &v) {
    sort(v.begin(), v.end(), [](P p1, P p2) {
        if (p1.first != p2.first) return p1.first < p2.first;
        return p1.second > p2.second;
    });

    set<P> candidate;
    {
        Points left1, right1;

        for (P p : v) right1.push(p);
        for (P p : v) {
            right1.pop(p);
            if (left1.max() >= p.second && p.second >= right1.min()) {
            } else {
                candidate.insert(p);
            }
            left1.push(p);
        }
    }
    sort(v.begin(), v.end(), [](P p1, P p2) {
        if (p1.first != p2.first) return p1.first < p2.first;
        return p1.second < p2.second;
    });

    {
        Points left2, right2;
        for (P p : v) right2.push(p);
        for (P p : v) {
            right2.pop(p);
            if (left2.min() <= p.second && p.second <= right2.max()) {
            } else {
                candidate.insert(p);
            }
            left2.push(p);
        }
    }

//    sort(candidate.begin(), candidate.end());
//    candidate.erase(unique(candidate.begin(), candidate.end()), candidate.end());

    vector<P> c2;
    for (P p : candidate) c2.push_back(p);

    ll ans = manhattan(c2);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    cin >> n;
    vector<P> v(n);
    for (P &p:v) cin >> p.first >> p.second;
    cout << solve(v) << endl;

//    int n = 10;
//    vector<P> v;
//    rep(i, 10) v.push_back({rand() / 100, rand() / 100});
//    ll a = manhattan(v);
//    ll b = solve(v);
//    cout << a << ' ' << b << endl;


}
