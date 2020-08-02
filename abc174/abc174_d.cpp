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
    int n;
    string s;
    cin >> n >> s;

    bool eq = [&] {
        return *min_element(s.begin(), s.end()) == *max_element(s.begin(), s.end());
    }();

    if (eq) {
        cout << 0 << endl;
        ret();
    }


    // 一番左にあるw
    int lw = [&] {
        rep(i, n) {
            if (s[i] == 'W') return i;
        }

        __throw_runtime_error("konai");
    }();
    // 一番右にあるr
    int rr = [&] {
        int ans = -1;
        rep(i, n) {
            if (s[i] == 'R') ans = i;
        }
        assert(ans > -1);
        return ans;
    }();

    // 一番右にあるrより左にあるw
    int wa = [&] {
        int ans = 0;
        rep(i, rr) {
            if (s[i] == 'W') ans++;
        }
        return ans;
    }();

    // 一番左にあるwより右にあるr
    int ra = [&] {
        int ans = 0;
        for (int i = wa; i < n; i++) {
            if (s[i] == 'R') ans++;
        }
        return ans;
    }();


    cout << min(wa, ra) << endl;

}
