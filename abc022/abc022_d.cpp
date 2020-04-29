#include <bits/stdc++.h>

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

std::istream &operator>>(std::istream &in, set<string> &o) {
    string a;
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

P calc_center(vector<P> &v, int n) {
    double x = 0, y = 0;
    for (P p : v) x += p.first, y += p.second;
    return P(x / n, y / n);
}

double calc_ave_dis(vector<P> &v, int n, P center) {
    double sum = 0;
    for (P p : v) {
        double w = p.first - center.first;
        double h = p.second - center.second;

        double ww = w * w;
        double hh = h * h;

        double now = sqrt(ww + hh);
        sum += now;
    }
    return sum / n;
}

int main() {
    int n;
    cin >> n;
    vector<P> first(n), second(n);
    rep(i, n) cin >> first[i].first >> first[i].second;
    rep(i, n) cin >> second[i].first >> second[i].second;

    P center1 = calc_center(first, n);
    P center2 = calc_center(second, n);

    double ave_dis1 = calc_ave_dis(first, n, center1);
    double ave_dis2 = calc_ave_dis(second, n, center2);

    printf("%.20f\n", ave_dis2 / ave_dis1);

}