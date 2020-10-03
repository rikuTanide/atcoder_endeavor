#include <bits/stdc++.h>
//#include "atcoder/all"
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


int main() {
//    ifstream cin("input.txt");
//    ofstream cout("output.txt");
    int n, m;
    cin >> n >> m;
    vector<P> count(m);
    rep(i, m) count[i].second = i;
    rep(_, n) {
        rep(i, m) {
            char a;
            cin >> a;
            if (a == '1') count[i].first++;
        }
    }

    sort(count.rbegin(), count.rend());

    rep(i, m) {
        cout << count[i].second + 1;
        if (i != m - 1) cout << ' ';
        else cout << endl;
    }

}