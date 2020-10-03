#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;
//#include "atcoder/all"

using namespace std;

const double PI = 3.14159265358979323846;
typedef int ll;
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


const int MAX = 10000+5;

int main() {
    int n, r;
    cin >> n >> r;

    vector<vector<P>> starts(MAX), ends(MAX);

    rep(_, n) {
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;

        starts[sy].push_back({sx, ex});
        ends[ey].push_back({sx, ex});

    }

    vector<int> prev_prev_imos(MAX);
    vector<int> prev_imos(MAX);

    vector<int> counts(MAX, 0);

    int s = 0, e = 0;
    rep(y, MAX) {
        for (P dx : ends[y]) counts[dx.first]--;
        for (P dx : ends[y]) counts[dx.second]++;
        for (P ix : starts[y]) counts[ix.first]++;
        for (P ix : starts[y]) counts[ix.second]--;

        vector<int> imos = counts;
        rep(i, MAX) {
            if (i == 0)continue;;
            imos[i] += imos[i - 1];
        }

        rep(x, MAX) if (imos[x] > 0) s++;

        rep(x, MAX) {
            if (prev_imos[x] == 0) continue;
            if (x == 0) e++;
            else if (x == MAX - 1) e++;
            else {
                if (prev_imos[x - 1] == 0) e++;
                if (prev_imos[x + 1] == 0) e++;
            }
            if (prev_prev_imos[x] == 0) e++;
            if (imos[x] == 0) e++;
        }

        prev_prev_imos = prev_imos;
        prev_imos = imos;


    }
    if (r == 1) {
        cout << s << endl;
    } else {
        cout << s << endl << e << endl;
    }

}
