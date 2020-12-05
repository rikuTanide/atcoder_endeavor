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

int main() {
    string s, k;
    cin >> s >> k;

    string alphabet = "1234567890abcdefghijklmnopqrstuvwxyz";
    int as = alphabet.size();

    vector<bool> in_s(as), in_k(as);
    rep(i, as) in_s[i] = find(s.begin(), s.end(), alphabet[i]) != s.end();
    rep(i, as) in_k[i] = find(k.begin(), k.end(), alphabet[i]) != k.end();

    vector<int> iis(as);
    CumulativeSum cs(s.size());
    {
        map<char, int> m;
        for (int i = s.size() - 1; i >= 0; i--) {
            char c = s[i];
            m[c] = i;
        }
        rep(i, as) iis[i] = m[alphabet[i]];

        rep(i, s.size()) {
            char c = s[i];
            if (i == m[c]) cs.set(i, 1);
        }
        cs.calculate();

    }

    vector<int> counts(as, 0);
    {
        map<char, int> m;
        for (char c : s) m[c]++;
        rep(i, as) counts[i] = m[alphabet[i]];
    }


    vector<double> v(as);
    rep(i, as) {
        bool is = in_s[i], ik = in_k[i];

        double d = [&]() -> double {
            if (is && ik) {
                return counts[i];
            }
            if (is && !ik) {
                int ii = iis[i];
                int f = cs.getSectionSum(0, ii);
                double cp = 1.0 / f;
                double wp = 1.0 - cp;
                double determine = counts[i] - 1;
                double fv = cp * 1 + wp * 3;
                return fv + determine;
            }
            if (!is && ik) {
                return 0.0;
            }
            if (!is && !ik) {
                int f = cs.getSectionSum(0, s.size());
                double cp = 1.0 / (f + 1);
                double wp = 1.0 - cp;
                return wp * 2;
            }
            __throw_runtime_error("konai");
        }();
        v[i] = d;
    }

    double ans = accumulate(v.begin(), v.end(), 0.0);
    printf("%.20f\n", ans);

}


