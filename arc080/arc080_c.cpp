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


vector<int> get_md(vector<int> &v) {
    int n = v.size();
    vector<int> ans(n, -1);
    rep(i, n) {
        if (i == 0) {
            if (v[i] == -1) {
                ans[i] = -1;
            } else {
                ans[i] = 0;
            }
        } else {
            if (v[i] == -1) {
                ans[i] = -1;
            } else {
                ans[i] = (ans[i - 1] + 1) % 2;
            }
        }
    }
    return ans;
}

int find_min_even(vector<int> &v, vector<int> &md) {
    int n = v.size();

    int mi = INT_MAX;
    int mi_i = -1;

    rep(i, n) {
        if (md[i] != 0) continue;
        if (mi > v[i]) {
            mi = v[i];
            mi_i = i;
        }
    }
    return mi_i;
}

int find_min_odd(vector<int> &v, vector<int> &md, int j) {
    int n = v.size();

    int mi = INT_MAX;
    int mi_i = -1;
    for (int i = j + 1; i < n && v[i] != -1; i++) {
        if (md[i] != 1) continue;

        if (mi > v[i]) {
            mi = v[i];
            mi_i = i;
        }
    }

    return
            mi_i;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    rep(i, n) cin >> v[i];


    rep(_, n / 2) {
        vector<int> md = get_md(v);
        int j = find_min_even(v, md);
        int k = find_min_odd(v, md, j);

        cout << v[j] << endl << v[k] << endl;
        v[j] = -1;
        v[k] = -1;
    }

    cout << endl;

}
