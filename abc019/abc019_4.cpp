#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<ll, ll> P;
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

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

struct Point {
    ll from, to, distance;
};

ll query(ll from, ll to) {
    printf("? %lld %lld\n", from + 1, to + 1);
    flush(cout);
    ll ans;
    cin >> ans;
    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<Point> distance;
    rep(i, n) {
        if (i == 0) continue;
        ll d = query(0, i);
        Point p = {0, i, d};
        distance.push_back(p);
    }

    Point p = *max_element(distance.begin(), distance.end(), [](Point p, Point q) {
        return p.distance < q.distance;
    });
    vector<Point> candidate;
    rep(i, n) {
        if (i == p.to || i == p.from) continue;
        ll d = query(p.to, i);
        Point q = {p.to, i, d};
        candidate.push_back(q);
    }

    Point ans = *max_element(candidate.begin(), candidate.end(), [](Point p, Point q) {
        return p.distance < q.distance;
    });

    printf("! %lld\n", ans.distance);

}

