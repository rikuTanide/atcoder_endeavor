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

struct Dice {

    int n, e, w, s, b, t;

    Dice north() {
        Dice d{t, e, w, b, n, s};
        return d;
    }

    Dice south() {
        Dice d{b, e, w, t, s, n};
        return d;
    }

    Dice west() {
        Dice d{n, b, t, s, w, e};
        return d;
    }

    Dice east() {
        Dice d{n, t, b, s, e, w};
        return d;
    }


    Dice roll(int to_e, int to_w, int to_s, int to_n) {
        Dice d = *this;
        rep(i, to_e) {
            d = d.east();
        }
        rep(i, to_w) {
            d = d.west();
        }
        rep(i, to_s) {
            d = d.south();
        }
        rep(i, to_n) {
            d = d.north();
        }
        return d;
    }

    Dice rotate(int i) {
        Dice d = *this;
        rep(j, i) {
            //  int n, e, w, s, b, t;
            d = Dice{d.w, d.n, d.s, d.e, d.b, d.t};
        }
        return d;
    }

    void print() {
        cout << n << e << w << s << b << t << endl;
    }

    vector<Dice> all() {
        vector<Dice> ds;
        rep(j, 4) {
            rep(k, 4) {
                rep(l, 4) {
                    Dice rt = (*this).rotate(l);
                    Dice rl = rt.roll(j, 0, 0, k);
                    ds.push_back(rl);
                }
            }
        }
        return ds;
    }

    bool operator!=(const Dice &d) const {
        return !(*this == d);
    }

    bool operator==(const Dice &f) const {
        return n == f.n &&
               e == f.e &&
               w == f.w &&
               s == f.s &&
               b == f.b &&
               t == f.t;
    }

    Dice normalize() {
        vector<Dice> ds = (*this).all();
        return *min_element(ds.begin(), ds.end());
    }

    bool operator<(const Dice &f) const {
        if (n < f.n)return true;
        if (n > f.n)return false;
        if (e < f.e)return true;
        if (e > f.e)return false;
        if (w < f.w)return true;
        if (w > f.w)return false;
        if (s < f.s)return true;
        if (s > f.s)return false;
        if (b < f.b)return true;
        if (b > f.b)return false;
        if (t < f.t)return true;
        if (t > f.t)return false;
        return false;
    }
};

int main() {
    int n;
    cin >> n;

    int ans = 1;

    //  int n, e, w, s, b, t;
    Dice dice = {5, 3, 4, 2, 6, 1};
    rep(_, n) {
        string s;
        cin >> s;
        if (s == "North") {
            dice = dice.north();
        } else if (s == "East") {
            dice = dice.east();
        } else if (s == "South") {
            dice = dice.south();
        } else if (s == "West") {
            dice = dice.west();
        } else if (s == "Right") {
            dice = dice.rotate(1);
        } else if (s == "Left") {
            dice = dice.rotate(3);
        } else {
            throw_with_nested("konai");
        }
        ans += dice.t;
    }
    cout << ans << endl;

}
