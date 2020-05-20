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

    void calculate(ll k) {
        for (int i = 0; i < numbers.size(); i++) {
            sums[i] = getSum(i - 1) + numbers[i];
        }
        rep(i, sums.size()) sums[i] = sums[i] % k;
    }

};

int main() {
    int n;
    ll k;
    cin >> n >> k;

    vector<ll> numbers(n + 1, 0);
    rep(i, n) cin >> numbers[i + 1];
    rep(i, n) numbers[i + 1]--;

    n++;

    CumulativeSum cs(n);
    rep(i, n) cs.set(i, numbers[i]);
    cs.calculate(k);

    ll ans = 0;
    map<ll, ll> m;


    auto pop = [&](ll i) {
        if (i < 0) return;
        m[cs.getSum(i)]--;
    };

    auto push = [&](ll i) {
        if (i < 0) return;
        m[cs.getSum(i)]++;
    };

    rep(i, n) {
        pop((-k) + i);
        push(i - 1);

        ll c = m[cs.getSum(i)];
        ans += c;
    }
    cout << ans << endl;
}