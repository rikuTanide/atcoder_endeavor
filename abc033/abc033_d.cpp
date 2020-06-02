#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = M_PI; //3.14159265358979323846;
typedef long long ll;
const long double EPS = 1e-10;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;


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

typedef long double ld;
typedef pair<ld, ld> P;


int main() {
    int n;
    cin >> n;

    vector<int> y(n), x(n);
    rep(i, n) cin >> x[i] >> y[i];

    ll acute_angle = 0;
    ll right = 0;

    rep(i, n) {
        vector<ld> angles;
        rep(j, n) if (j != i) angles.push_back(atan2l(y[j] - y[i], x[j] - x[i]));
        sort(angles.begin(), angles.end());
        rep(j, n - 1) angles.push_back(angles[j] + 2 * PI);
        int k = 0;

        rep(j, n - 1) {
            while (angles[k + 1] - angles[j] < PI / 2 - EPS) k++;
            acute_angle += (k - j);
            assert(PI / 2 - EPS <= (angles[k + 1] - angles[j]));
            if (angles[k + 1] - angles[j] < PI / 2 + EPS) right++;
        }
    }

    ll all_angle = n * (n - 1) * (n - 2) / 6;
    ll obtuse = 3 * all_angle - acute_angle - right;
    ll acute = all_angle - right - obtuse;

    printf("%lld %lld %lld\n", acute, right, obtuse);

}
