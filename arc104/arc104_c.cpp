#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;
//#include "atcoder/all"

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
    int n;
    cin >> n;
    vector<P> v(n);
    for (P &p:v)cin >> p.first >> p.second, p.first--, p.second--;

    for (P p: v) {
        if (p.first == -2) continue;
        if (p.second == -2)continue;
        if (p.first >= p.second) {
            cout << "No" << endl;
            ret();
        }
    }

    {
        map<int, int> counter;
        for (P p : v) counter[p.first]++;
        for (P p : v) counter[p.second]++;

        for (auto e : counter) {
            if (e.first == -2) continue;
            if (e.second >= 2) {
                cout << "No" << endl;
                ret();
            }
        }
    }


    map<int, int> in_out, out_in;
    for (P p : v)if (p.first != -2) in_out[p.first] = p.second;
    for (P p : v)if (p.second != -2) out_in[p.second] = p.first;

    auto in_out_is = [&](int i, int j) -> bool {
        if (in_out.find(i) == in_out.end())return true;
        return in_out[i] == j || in_out[i] == -2;
    };


    auto out_in_is = [&](int i, int j) -> bool {
        if (out_in.find(i) == out_in.end())return true;
        return out_in[i] == j || out_in[i] == -2;
    };


    auto check = [&](int now, int i) -> bool {
        for (int left = now; left < now + i; left++) {
            int right = left + i;
            if (!in_out_is(left, right)) return false;
            if (!out_in_is(right, left)) return false;
        }
        return true;
    };

    int now = 0;
    while (now < n) {
        int i = [&]() -> int {
            for (int i = 1; now + i * 2 < 2 * n; i++) {
                if (check(now, i)) return i;
            }
            return -1;
        }();

        if (i == -1) {
            cout << "No" << endl;
            ret();
        }
//        cout << i << endl;
        now += i * 2;
    }

//    cout << "Yes" << endl;
throw_with_nested("hoge");
}
