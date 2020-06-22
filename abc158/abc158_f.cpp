#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
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

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

int main() {
    int n;
    cin >> n;

    set<set<P>> ans;

    vector<P> robots(n);
    for (P &p: robots) cin >> p.first >> p.second;
    sort(robots.begin(), robots.end());

    rep(i, 1 << n) {

        set<P> now;

        queue<P> q;
        rep(j, n) if ((i >> j) & 1) q.push(robots[j]), now.insert(robots[j]);


        while (!q.empty()) {
            P t = q.front();
            q.pop();
            for (P p : robots) {
                if (p == t) continue;
                if (t.first <= p.first && p.first < t.first + t.second) {
                    now.insert(p);
                    q.push(p);
                }
            }
        }

        ans.insert(now);

    }

    cout << ans.size() << endl;

}
