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

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    vector<int> tmp(26, 0);

    vector<vector<int>> cache(n - k + 1);

    rep(i, k) {
        char c = s[i];
        tmp[c - 'a']++;
    }

    cache[0] = tmp;

    for (int i = 1; i <= n - k; i++) {
        vector<int> next = tmp;
        char out = s[i - 1];
        char in = s[i + k - 1];
        next[out - 'a']--;
        next[in - 'a']++;
        cache[i] = next;
        tmp = next;
    }

    set<vector<int>> used;

    for (int i = k; i <= n - k; i++) {
        used.insert(cache[i - k]);
        if (used.find(cache[i]) != used.end()) {
            cout << "YES" << endl;
            ret();
        }
    }
    cout << "NO" << endl;
}
