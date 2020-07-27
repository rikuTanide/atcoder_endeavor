#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
typedef pair<int, int> P;
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
    int n, m;
    cin >> n >> m;
    vector<int> as(n), bs(m);

    rep(i, n) cin >> as[i];
    rep(i, m) cin >> bs[i];

    map<int, vector<P>> mp;

    rep(i, n) {
        rep(j, m) {
            int sum = as[i] + bs[j];
            if (mp.find(sum) == mp.end()) {
                mp[sum].push_back(P(i, j));
            } else {
                for (P p : mp[sum]) {
                    if (i == p.first || j == p.second) continue;
                    printf("%d %d %d %d\n", i, j, p.first, p.second);
                    ret();
                }
                mp[sum].push_back(P(i, j));
            }
        }
    }
    cout << -1 << endl;

}
