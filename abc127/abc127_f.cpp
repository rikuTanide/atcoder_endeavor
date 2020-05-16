#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<double, double> P;
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
    int q;
    cin >> q;

    ll sum = 0;
    priority_queue<ll> left;
    priority_queue<long long, vector<long long>, greater<long long> > right;

    ll l_sum = 0, r_sum = 0;

    rep(_, q) {
        int type;
        cin >> type;

        if (type == 1) {
            ll a, b;
            cin >> a >> b;
            sum += b;

            if (left.size() > right.size()) {
                // right に
                int t = left.top();
                if (a >= t) {
                    right.push(a);
                    r_sum += a;
                } else {
                    left.pop();
                    l_sum -= t;
                    left.push(a);
                    l_sum += a;
                    right.push(t);
                    r_sum += t;
                }
            } else {
                // left に
                if (left.empty()) left.push(a), l_sum += a;
                else {
                    int t = right.top();
                    if (a <= t) {
                        left.push(a);
                        l_sum += a;
                    } else {
                        right.pop();
                        r_sum -= t;
                        right.push(a);
                        r_sum += a;
                        left.push(t);
                        l_sum += t;
                    }
                }
            }

        } else {
            ll x = left.top();
            ll res = (x * (ll) left.size() - l_sum)
                     + (r_sum - x * (ll) right.size()) + sum;
            cout << x << ' ' << res << endl;
        }
    }

}