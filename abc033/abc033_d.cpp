#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
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

bool equal(ld a, ld b) {
    return fabs(a - b) < DBL_EPSILON;
}

ld diff(P a, P b) {
    ld x = a.first - b.first;
    ld y = a.second - b.second;
    ld xx = x * x;
    ld yy = y * y;

    return sqrtl(xx + yy);
}

int main() {
    int n;
    cin >> n;
    assert(n <= 100);


    vector<P> v(n);
    for (P &p : v) cin >> p.first >> p.second;

    int j = 0, k = 0, l = 0;

    for (int x = 0; x < n; x++) {
        for (int y = x + 1; y < n; y++) {
            for (int z = y + 1; z < n; z++) {


                P a = v[x];
                P b = v[y];
                P c = v[z];

                ld e1 = diff(a, b);
                ld e2 = diff(b, c);
                ld e3 = diff(c, a);

                vector<ld> tmp = {e1, e2, e3};
                sort(tmp.begin(), tmp.end());
                e1 = tmp[0];
                e2 = tmp[1];
                e3 = tmp[2];

                ld aabb = e1 * e1 + e2 * e2;
                ld cc = e3 * e3;

                if (equal(aabb, cc)) {
                    k++;
                } else if (cc < aabb) {
                    j++;
                } else {
                    l++;
                }


            }
        }
    }

    printf("%d %d %d\n", j, k, l);

}
