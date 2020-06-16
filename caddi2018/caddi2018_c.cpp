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
    cin >> n;
    vector<ll> v(n);
    for (ll &l:v) cin >> l;

    int ans = INT_MAX;

    for (int i = 0; i <= n; i++) {
        vector<ll> minus;
        vector<ll> plus;

        for (int j = 0; j < i; j++) minus.push_back(v[j]);
        for (int j = i; j < n; j++) plus.push_back(v[j]);

        int count = 0;
        reverse(minus.begin(), minus.end());
        for (ll l : minus) {
            if (l > 0) {
                l *= -2;
                count++;
            }
        }

        for (ll l : plus) {
            if (l < 0) {
                l *= -2;
                count++;
            }
        }

        for (int j = 0; j < (int) minus.size() - 1; j++) {
            while (minus[j] < minus[j + 1]) {
                minus[j + 1] *= 4;
                count += 2;
            }
        }

        for (int j = 0; j < (int) plus.size() - 1; j++) {
            while (plus[j] > plus[j + 1]) {
                plus[j + 1] *= 4;
                count += 2;
            }
        }

        cmin(ans, count);


    }

    cout << ans <<endl;
}
