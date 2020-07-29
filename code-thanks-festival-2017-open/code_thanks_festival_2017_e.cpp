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

int pow2(int i) {
    int a = 1;
    rep(j, i) a *= 5;
    return a;
}

int main() {
    int n;
    cin >> n;

    vector<bool> ans(n);

    for (int s = 0; s < n; s += 5) {
        vector<int> q(n, 0);
        for (int t = s; t < min(n, s + 5); t++) {
            int k = pow2(t % 5);
            q[t] = k;
        }
        cout << '?' << ' ';
        for (int v : q) cout << v << ' ';
        cout << endl << flush;

        int a;
        cin >> a;
        int sum = accumulate(q.begin(), q.end(), 0);
        a -= sum * 8;

        vector<int> ap;
        while (a > 0) {
            ap.push_back(a % 5);
            a /= 5;
        }

        while (ap.size() < 5) {
            ap.push_back(0);
        }

        for (int t = s; t < min(n, s + 5); t++) {
            int f = ap[t % 5];
            ans[t] = f == 1 || f == 3;
        }
    }

    cout << '!' << ' ';
    for (bool b : ans) cout << b << ' ';
    cout << endl;

}
