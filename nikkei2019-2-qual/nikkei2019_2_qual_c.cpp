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

bool check(vector<ll> as, vector<ll> bs) {
    int n = as.size();
    sort(as.begin(), as.end());
    sort(bs.begin(), bs.end());
    rep(i, n) {
        if (as[i] > bs[i]) return false;
    }
    return true;
}

void sort_tuple(vector<ll> &as, vector<ll> &bs) {
    int n = as.size();
    vector<P> ps(n);
    rep(i, n) ps[i].first = bs[i];
    rep(i, n) ps[i].second = as[i];

    sort(ps.begin(), ps.end());

    rep(i, n) as[i] = ps[i].second;
    rep(i, n) bs[i] = ps[i].first;
}

int main() {
    int n;
    cin >> n;
    vector<ll> as(n), bs(n);
    rep(i, n) cin >> as[i];
    rep(i, n)cin >> bs[i];

    if (!check(as, bs)) {
        cout << "No" << endl;
        ret();
    }

    sort_tuple(as, bs);

    map<ll, int> index;
    rep(i, n) assert(index.find(as[i]) == index.end());
    rep(i, n) index[as[i]] = i;

    multiset<ll> wait;
    for (ll l : as) wait.insert(l);

    rep(i, n) {
        if (as[i] <= bs[i]) {
            cout << "Yes" << endl;
            ret();
        }

        ll o = as[i];

        ll sp = *wait.begin();
        ll spi = index[sp];

        swap(as[i], as[spi]);
        swap(index[o], index[sp]);

        assert(as[i] <= bs[i]);

        wait.erase(wait.find(sp));

    }

    cout << "No" << endl;

}
