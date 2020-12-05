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

class CumulativeSum {
    vector<ll> numbers;
    vector<ll> sums;

public:
    CumulativeSum(int n) {
        numbers.resize(n);
        sums.resize(n);
    }

    void set(int i, ll value) {
        numbers[i] = value;
    }

    ll getSum(int i) {
        if (i == -1) return 0;
        if (i == sums.size()) return sums.back();
        return sums[i];
    }

    ll getSectionSum(int start, int end) {
        return getSum(end) - getSum(start - 1);
    }

    void build() {
        for (int i = 0; i < numbers.size(); i++) {
            sums[i] = getSum(i - 1) + numbers[i];
        }
    }

};


ll cnt(vector<ll> &v) {
    int n = v.size();
    CumulativeSum cs(n);
    rep(i, n) cs.set(i, v[i]);
    cs.build();

    ll sum = accumulate(v.begin(), v.end(), 0ll);
    int mid = [&] {
        rep(i, n) {
            if (cs.getSum(i) * 2 >= sum) {
                return i;
            }
        }
        __throw_runtime_error("konai");
    }();

    ll ans = 0;
    rep(i, n) {
        ll d = abs(i - mid);
        ll mo = v[i] * d;
        ans += mo;
    }
    return ans;
}


int main() {
    int h, w, k;
    cin >> h >> w >> k;
    vector<P> ex(k);
    for (P &p:ex) cin >> p.first >> p.second, p.first--, p.second--;

    vector<ll> vertical(h, w);
    vector<ll> horizontal(w, h);

    for (P p : ex) vertical[p.first]--;
    for (P p : ex) horizontal[p.second]--;

    ll va = cnt(vertical);
    ll ha = cnt(horizontal);

    cout << va + ha << endl;


}
