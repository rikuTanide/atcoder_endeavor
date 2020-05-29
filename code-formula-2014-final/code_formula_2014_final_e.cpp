#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const long double EPS = 1e-9;

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

std::istream &operator>>(std::istream &in, set<char> &o) {
    string a;
    in >> a;
    for (char c : a) o.insert(c);
    return in;
}

std::istream &operator>>(std::istream &in, queue<int> &o) {
    ll a;
    in >> a;
    o.push(a);
    return in;
}

bool contain(set<char> &s, char a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;


P operator+(P &p1, P &p2) {
    return P(p1.first + p2.first, p1.second + p2.second);
}

std::ostream &operator<<(std::ostream &in, const P &o) {
    in << o.first << ' ' << o.second;
    return in;
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

    void calculate() {
        for (int i = 0; i < numbers.size(); i++) {
            sums[i] = getSum(i - 1) + numbers[i];
        }
    }

};


P f(int n, int k, map<P, P> &fmem) {
    assert(n > 0 || k == 0);
    if (n <= 0) return P(0, 0);
    if (n == 1 && k == 0) return P(0, 1);
    if (n == 2 && k == 0) return P(1, 0);

    if (fmem.find(P(n, k)) != fmem.end()) {
        return fmem[P(n, k)];
    }

    P x = f(n - 1, k / 2, fmem);
    P y = f(n - 2, k / 4, fmem);

    P ans = (k % 2 == 0) ? x + y : y + x;
    fmem[P(n, k)] = ans;
    return ans;
}

bool check(int n, int k, int l, int r, CumulativeSum &as, CumulativeSum &bs, vector<ll> &feb, map<P, P> &fmem,
           map<vector<int>, bool> &cmem) {

    vector<int> index = {n, k, l, r};
    if (cmem.find(index) != cmem.end()) return cmem[index];

    P p = f(n, k, fmem);
    ll ac = as.getSectionSum(l, r - 1);
    ll bc = bs.getSectionSum(l, r - 1);

    if (p.first != ac || p.second != bc) return false;
    if (ac + bc == 1) return true;

    ll feb1 = feb[n - 1];
    ll feb2 = feb[n - 2];

//    assert(feb1 + feb2 == ac + bc);

    if (k % 2 == 0) {
        bool b1 = check(n - 1, k / 2, l, l + feb1, as, bs, feb, fmem, cmem);
        bool b2 = check(n - 2, k / 4, l + feb1, r, as, bs, feb, fmem, cmem);
        bool ans = b1 && b2;
        cmem[index] = ans;
        return ans;
    } else {
        bool b1 = check(n - 2, k / 4, l, l + feb2, as, bs, feb, fmem, cmem);
        bool b2 = check(n - 1, k / 2, l + feb2, r, as, bs, feb, fmem, cmem);
        bool ans = b1 && b2;
        cmem[index] = ans;
        return ans;
    }


}


int main() {
    string s;
    cin >> s;

    if (s == "b") {
        printf("1 0\n");
        ret();
    } else if (s == "a") {
        printf("0 1\n");
        ret();
    }

    int n = s.size();

    CumulativeSum as(n), bs(n);
    rep(i, n) if (s[i] == 'a') as.set(i, 1); else bs.set(i, 1);
    as.calculate();
    bs.calculate();

//    cout << 1 << ' ' << 0 << ' ' << f(1, 0) << endl;
//    cout << 2 << ' ' << 0 << ' ' << f(2, 0) << endl;


//    for (int p = 3; p < 10; p++) {
//        for (int q = 0; q < (1 << (p - 2)); q++) {
//            cout << p << ' ' << q << ' ' << f(p, q) << endl;
//        }
//    }

    vector<ll> feb(30);
    feb[0] = -INF;
    feb[1] = 1;
    feb[2] = 1;
    rep(i, 20) {
        if (i <= 2) continue;
        feb[i] = feb[i - 1] + feb[i - 2];
    }

    auto it = find(feb.begin(), feb.end(), s.size());
    assert(it != feb.end());
    int p = distance(feb.begin(), it);

    map<P, P> fmem;
    map<vector<int>, bool> cmem;

    rep(q, 1 << (p - 2)) {
        bool b = check(p, q, 0, n, as, bs, feb, fmem, cmem);
        if (!b) continue;
        cout << p << ' ' << q << endl;
        ret();
    }

}
