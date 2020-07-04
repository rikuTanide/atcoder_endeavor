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
const int z = 26;

vector<int> count_alp(string &s) {
    int n = s.size();
    vector<int> v(z, 0);
    rep(i, n) v[s[i] - 'A']++;
    return v;
}

int main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    vector<int> cs1 = count_alp(s1), cs2 = count_alp(s2), cs3 = count_alp(s3);

    rep(i, z) if (cs3[i] > (cs1[i] + cs2[i])) {
            cout << "NO" << endl;
            ret();
        }

    int u2 = 0, u1 = 0;
    rep(i, z) {
        if (min(cs1[i], cs2[i]) > cs3[i]) continue;
        if (cs1[i] < cs3[i]) u2 += cs3[i] - cs1[i];
        if (cs2[i] < cs3[i]) u1 += cs3[i] - cs2[i];
    }
    int n = s1.size() / 2;

    if (u2 > n || u1 > n) {
        cout << "NO" << endl;
        ret();
    }

    cout << "YES" << endl;
}
