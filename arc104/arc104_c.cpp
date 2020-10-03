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

bool rec(vector<P> &v, int now, int n, map<int, int> &in_out, map<int, int> &out_in) {

    if (now == n * 2) {
        return true;
    }

    auto in_out_is = [&](int i, int j) -> bool {
        if (in_out.find(i) == in_out.end())return true;
        return in_out[i] == j || in_out[i] == -2;
    };


    auto out_in_is = [&](int i, int j) -> bool {
        if (out_in.find(i) == out_in.end())return true;
        return out_in[i] == j || out_in[i] == -2;
    };

    auto in_out_has = [&](int a) -> bool {
        if (in_out.find(a) != in_out.end())return true;
        return false;
    };

    auto out_in_has = [&](int a) -> bool {
        if (out_in.find(a) != out_in.end())return true;
        return false;
    };

    auto check = [&](int now, int i) -> bool {
        for (int left = now; left < now + i; left++) {
            int right = left + i;
            if (in_out_has(right)) return false;
            if (out_in_has(left)) return false;

            if (!in_out_is(left, right)) return false;
            if (!out_in_is(right, left)) return false;
        }
        return true;
    };

    for (int i = 1; now + i * 2 <= 2 * n; i++) {
        if (check(now, i)) {
            bool b = rec(v, now + i * 2, n, in_out, out_in);
            if (b) return true;
        }
    }
    return false;
}

bool solve(int n, vector<P> &v) {
//    int n;
//    cin >> n;
//    vector<P> v(n);
//    for (P &p:v)cin >> p.first >> p.second, p.first--, p.second--;

//    vector<P> k = {{0,  1},
//                   {-2, 4},
//                   {-2, 5}};
//    if (v == k) {
//        cout << endl;
//    }


    for (P p: v) {
        if (p.first == -2) continue;
        if (p.second == -2)continue;
        if (p.first >= p.second) {
            return false;
        }
    }

    {
        map<int, int> counter;
        for (P p : v) counter[p.first]++;
        for (P p : v) counter[p.second]++;

        for (auto e : counter) {
            if (e.first == -2) continue;
            if (e.second >= 2) {
                return false;
            }
        }

        for (P p : v) {
            if (p.first == -2 && p.second != -2) {
                bool b = false;
                for (int i = 0; i < p.second; i++) {
                    if (counter.find(i) == counter.end()) b = true;
                }
                if (!b) {
                    return false;
                }
            }
        }


        for (P p : v) {
            if (p.first != -2 && p.second == -2) {
                bool b = false;
                for (int i = 0; i < p.first; i++) {
                    if (counter.find(i) == counter.end()) b = true;
                }
                if (!b) {
                    return false;
                }
            }
        }

    }


    map<int, int> in_out, out_in;
    for (P p : v)if (p.first != -2) in_out[p.first] = p.second;
    for (P p : v)if (p.second != -2) out_in[p.second] = p.first;


    return rec(v, 0, 2 * n, in_out, out_in);

}

bool check(vector<P> v) {

    for (P p : v) if (p.first >= p.second)return false;

    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            int xa = v[i].first;
            int xb = v[i].second;
            int ya = v[j].first;
            int yb = v[j].second;

            if (
                    (xa <= ya && ya <= xb)
                    || (xa <= yb && yb <= xb)
                    || (ya <= xa && xa <= yb)
                    || (ya <= xb && xb <= yb)
                    ) {
                if (xa - xb != ya - yb) return false;
            }

        }
    }
    return true;

}

int main() {
    int n;
    cin >> n;
    vector<P> v(n);
    for (P &p:v)cin >> p.first >> p.second, p.first--, p.second--;
    bool b = solve(n, v);
    cout << (b ? "Yes" : "No") << endl;
}

int main3() {
    int n = 3;

    vector<int> arr(2 * n);
    rep(i, 2 * n)arr[i] = i;

    do {
        vector<P> v(n);
        rep(i, 2 * n) if (i % 2 == 0) v[i / 2].first = arr[i];
        rep(i, 2 * n) if (i % 2 == 1) v[i / 2].second = arr[i];

        bool b1 = check(v);

        rep(i, 1 << (2 * n)) {
            vector<P> u = v;
            rep(j, 2 * n) {
                if ((i >> j) & 1) {
                    if (j >= n) u[j - n].second = -2;
                    else u[j].first = -2;
                }
            }
            bool b2 = solve(n, u);
            if (b1 != b2) {

                if (b1 && !(b2)) {
                    cout << "tf" << endl;
                } else {
                    cout << "ft" << endl;
                }

                for (P p : u) {
                    printf("%lld %lld\n", p.first, p.second);
                }
                cout << endl;
            }
        }


    } while (std::next_permutation(arr.begin(), arr.end()));
}