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


long double combf(ll l, ll r, vector<long double> &facts) {

    long double la = facts[l];
    long double lr = facts[l - r];
    long double d = facts[r];

    return la - lr - d;

}


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


int main() {
    vector<long double> facts(pow(10, 7));
    facts[0] = 0;
    facts[1] = 0;
    rep(i, pow(10, 7) - 1) {
        if (i <= 1) continue;
        facts[i] = facts[i - 1] + log10l(i);
    }

    int n, m;
    cin >> n >> m;

    vector<int> v(m);
    rep(i, m) cin >> v[i];

    CumulativeSum cs(m);
    rep(i, m) cs.set(i, v[i]);
    cs.build();

    long double tmp = 0;
    rep(i, m) tmp += combf(n - cs.getSum(i - 1), v[i], facts);
    tmp -= (log10l(m) * n);
    cout << ceil(abs(tmp)) << endl;

}
