#include <bits/stdc++.h>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

std::istream &operator>>(std::istream &in, set<int> &o) {
    ll a;
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

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef pair<double, double> P;

//const ll mod = 1e10;
typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;

double arg(P p) {
    return atan2(p.first, p.second);
}

int main() {
    int n;
    cin >> n;
    vector<P> points(n);
    for (P &p:points) cin >> p.first >> p.second;

    sort(points.begin(), points.end(), [](P p1, P p2) {
        return arg(p1) < arg(p2);
    });

    double ans = 0;

    for (int l = 0; l < n; l++) {
        vector<int> v;
        double y = 0, x = 0;
        for (int r = l; r < l + n; r++) {
            v.push_back(r);
            P p = points[r % n];

            y += p.first;
            x += p.second;

            double xx = x * x, yy = y * y;
            double now = sqrt(xx + yy);

            cmax(ans, now);

        }
    }


    cout << setprecision(20) <<  ans << endl;

}