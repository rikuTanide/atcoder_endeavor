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

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

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

const int mod = 1000000007;


struct Rect {
    double top, right, bottom, left;
    bool be;

    Rect intersection(Rect other) {
        Rect next;
        next.top = min(top, other.top);
        next.right = min(right, other.right);
        next.bottom = max(bottom, other.bottom);
        next.left = max(left, other.left);

        if (next.top < next.bottom) next.be = false;
        else if (next.right < next.left) next.be = false;
        else next.be = true;

        return next;
    }

};

struct Norm {
    double x, y, rate;

    Rect cover(double t) {
        Rect result;
        double m = t / rate;
        result.top = y + m;
        result.right = x + m;
        result.bottom = y - m;
        result.left = x - m;
        if (result.top < result.bottom) result.be = false;
        else if (result.right < result.left) result.be = false;
        else result.be = true;
        return result;
    }

    friend std::istream &operator>>(std::istream &in, Norm &o) {
        cin >> o.x >> o.y >> o.rate;
        return in;
    }

};

bool check(vector<Norm> &norms, double t) {
    double inf = 10e10;
    Rect now = {inf, inf, -inf, -inf};
    for (Norm norm : norms) {
        Rect cover = norm.cover(t);
        now = now.intersection(cover);
    }
    return now.be;
}

int main() {
    int n;
    cin >> n;
    vector<Norm> norms(n);
    rep(i, n)cin >> norms[i];//.x >> norms[i].y >> norms[i].rate;

    if (check(norms, 0)) {
//    if (check(norms, 3.333)) {
        cout << 0 << endl;
        ret();
    }

    double floor = 0, ceil = INF;
    rep(i, 100000) {
        double mid = (floor + ceil) / 2;
        bool b = check(norms, mid);
        if (b) ceil = mid;
        else floor = mid;
    }
    printf("%.20f\n", ceil);
}
