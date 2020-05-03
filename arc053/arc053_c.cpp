#include <bits/stdc++.h>


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

typedef pair<ll, ll> P;

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;


int main() {
    int n;
    cin >> n;

    vector<P> magics(n);
    rep(i, n) cin >> magics[i].first >> magics[i].second;

    vector<P> plus, minus;

    for (P p : magics)
        if (p.first > p.second) plus.push_back(p);
        else minus.push_back(p);


    sort(plus.rbegin(), plus.rend(), [&](P p1, P p2) {
        return p1.second < p2.second;
    });

    sort(minus.begin(), minus.end(), [&](P p1, P p2) {
        return p1.first < p2.first;
    });

    ll ans = 0;
    ll now = 0;
    for (P p : minus) {
        now += p.first;
        cmax(ans, now);
        now -= p.second;
        cmax(ans, now);
    }

    for (P p : plus) {
        now += p.first;
        cmax(ans, now);
        now -= p.second;
        cmax(ans, now);
    }
    cout << ans << endl;
}
