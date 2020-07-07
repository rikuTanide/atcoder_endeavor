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
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> solve_users(m, 0);

    vector<vector<bool>> solves(n, vector<bool>(m, false));

    rep(_, q) {
        int method;
        cin >> method;
        if (method == 1) {

            int ni;
            cin >> ni;
            ni--;

            int ans = 0;
            rep(i, m) {
                if (!solves[ni][i]) continue;
                ans += n - solve_users[i];
            }
            cout << ans << endl;
        } else {
            int ni, mi;
            cin >> ni >> mi;

            ni--;
            mi--;
            solves[ni][mi] = true;
            solve_users[mi]++;
        }

    }

}
