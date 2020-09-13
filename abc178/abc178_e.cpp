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
    vector<P> v(n);
    for (P &p:v) cin >> p.first >> p.second;

    sort(v.begin(), v.end());

    Points left, right;

    for (P p : v) right.push(p);

    vector<P> candidate;
    for (P p : v) {
        right.pop(p);
        if (left.max() > p.second && p.second > right.min()) {
        } else if (left.min() < p.second && p.second < right.max()) {
        } else {
            candidate.push_back(p);
        }
        left.push(p);
    }

    ll ans = manhattan(candidate);
    cout << ans << endl;
}
