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

bool test(
        vector<int> &as, int ai,
        vector<int> &bs, int bi,
        vector<int> &cs, int ci
) {
    if (as.size() <= ai) return false;
    if (bs.size() <= bi) return false;
    if (cs.size() <= ci) return false;
    vector<int> k = {as[ai], bs[bi], cs[ci]};
    sort(k.begin(), k.end());

    return k[0] == 1 && k[1] == 2 && k[2] == 3;
}

bool check(int ai,
           int bi,
           int ci,
           int di,
           vector<int> &as,
           vector<int> &bs,
           vector<int> &cs,
           vector<int> &ds,
           vector<vector<vector<vector<bool>>>> &memo,
           vector<vector<vector<vector<bool>>>> &visited
) {
    if (visited[ai][bi][ci][di]) return memo[ai][bi][ci][di];

    if (ai == as.size() && bi == bs.size() && ci == cs.size() && di == ds.size()) {
        return true;
    }

    {
        // a b c
        bool ok = test(as, ai, bs, bi, cs, ci);
        if (ok) {
            bool next = check(ai + 1, bi + 1, ci + 1, di,
                              as, bs, cs, ds, memo, visited);
            if (next)memo[ai][bi][ci][di] = true;
        }
    }

    {
        // a b d
        bool ok = test(as, ai, bs, bi, ds, di);
        if (ok) {
            bool next = check(ai + 1, bi + 1, ci, di + 1,
                              as, bs, cs, ds, memo, visited);
            if (next)memo[ai][bi][ci][di] = true;
        }
    }

    {
        // a c d
        bool ok = test(as, ai, cs, ci, ds, di);
        if (ok) {
            bool next = check(ai + 1, bi, ci + 1, di + 1,
                              as, bs, cs, ds, memo, visited);
            if (next)memo[ai][bi][ci][di] = true;
        }
    }

    {
        // b c d
        bool ok = test(bs, bi, cs, ci, ds, di);
        if (ok) {
            bool next = check(ai, bi + 1, ci + 1, di + 1,
                              as, bs, cs, ds, memo, visited);
            if (next) memo[ai][bi][ci][di] = true;
        }
    }

    visited[ai][bi][ci][di] = true;
    return memo[ai][bi][ci][di];
}


void restore(int ai,
             int bi,
             int ci,
             int di,
             vector<int> &as,
             vector<int> &bs,
             vector<int> &cs,
             vector<int> &ds,
             vector<vector<vector<vector<bool>>>> &memo,
             vector<vector<vector<vector<bool>>>> &visited
) {
    if (ai == as.size() && bi == bs.size() && ci == cs.size() && di == ds.size()) {
        return;
    }

    {
        // a b c
        bool ok = test(as, ai, bs, bi, cs, ci);
        if (ok) {
            bool next = check(ai + 1, bi + 1, ci + 1, di,
                              as, bs, cs, ds, memo, visited);
            if (next) {
                cout << '4' << endl;
                restore(ai + 1, bi + 1, ci + 1, di,
                        as, bs, cs, ds, memo, visited);
                return;
            }
        }
    }

    {
        // a b d
        bool ok = test(as, ai, bs, bi, ds, di);
        if (ok) {
            bool next = check(ai + 1, bi + 1, ci, di + 1,
                              as, bs, cs, ds, memo, visited);
            if (next) {
                cout << '3' << endl;
                restore(ai + 1, bi + 1, ci, di + 1,
                        as, bs, cs, ds, memo, visited);
                return;
            }
        }
    }

    {
        // a c d
        bool ok = test(as, ai, cs, ci, ds, di);
        if (ok) {
            bool next = check(ai + 1, bi, ci + 1, di + 1,
                              as, bs, cs, ds, memo, visited);
            if (next) {
                cout << '2' << endl;
                restore(ai + 1, bi, ci + 1, di + 1,
                        as, bs, cs, ds, memo, visited);
                return;
            }
        }
    }

    {
        // b c d
        bool ok = test(bs, bi, cs, ci, ds, di);
        if (ok) {
            bool next = check(ai, bi + 1, ci + 1, di + 1,
                              as, bs, cs, ds, memo, visited);
            if (next) {
                cout << '1' << endl;
                restore(ai, bi + 1, ci + 1, di + 1,
                        as, bs, cs, ds, memo, visited);
                return;
            }
        }
    }

    __throw_runtime_error("konai");

}


int main() {
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    vector<int> as(a), bs(b), cs(c), ds(d);
    rep(i, a) cin >> as[i];
    rep(i, b) cin >> bs[i];
    rep(i, c) cin >> cs[i];
    rep(i, d) cin >> ds[i];

    ll sum = a + b + c + d;

    if (sum % 3 != 0) {
        cout << "No" << endl;
        ret();
    }

    if (sum / 3 != n) {
        cout << "No" << endl;

        ret();
    }

    vector<vector<vector<vector<bool>>>> memo(n + 1,
                                              vector<vector<vector<bool>>>(n + 1,
                                                                           vector<vector<bool>>(n + 1,
                                                                                                vector<bool>(n + 1,
                                                                                                             false))));

    vector<vector<vector<vector<bool>>>> visited(n + 1,
                                                 vector<vector<vector<bool>>>(n + 1,
                                                                              vector<vector<bool>>(n + 1,
                                                                                                   vector<bool>(n + 1,
                                                                                                                false))));

    bool k = check(0, 0, 0, 0, as, bs, cs, ds, memo, visited);

    if (!k) {
        cout << "No" << endl;
        ret();
    }

    cout << "Yes" << endl;
    restore(0, 0, 0, 0, as, bs, cs, ds, memo, visited);

}
