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

struct Rabbit {
    ll x;
    char d;
};

int main() {
    int n;
    ll l;
    cin >> n >> l;
    vector<Rabbit> rabbits(n);
    for (Rabbit &rabbit: rabbits) cin >> rabbit.x >> rabbit.d;

    vector<ll> follower_r(n, 0), follower_l(n, 0);
    rep(i, n) {
        if (i == 0)continue;
        if (rabbits[i].d != 'R') continue;
        if (rabbits[i - 1].d != 'R') continue;
        follower_r[i] = follower_r[i - 1] + 1;
    }
    for (int i = n - 2; i >= 0; i--) {
        if (rabbits[i].d != 'L') continue;
        if (rabbits[i + 1].d != 'L') continue;
        follower_l[i] = follower_l[i + 1] + 1;
    }

    ll ans = 0;

    auto move = [&](int i, ll to) {
        ll from = rabbits[i].x;
        ll sub = abs(from - to);
        ans += sub;
        rabbits[i].x = to;
    };

    rep(i, n - 1) {
        if (!(rabbits[i].d == 'R' && rabbits[i + 1].d == 'L')) continue;
        if (follower_r[i] > follower_l[i + 1]) {
            move(i, rabbits[i + 1].x - 1);
        } else {
            move(i + 1, rabbits[i].x + 1);
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (rabbits[i].d != 'R') continue;
        if (i == n - 1) {
            move(i, l);
            continue;
        }
        if (rabbits[i + 1].d == 'R') {
            move(i, rabbits[i + 1].x - 1);
            continue;
        }
        assert(rabbits[i + 1].x == rabbits[i].x + 1);
    }

    rep(i, n) {
        if (rabbits[i].d != 'L') continue;
        if (i == 0) {
            move(i, 1);
            continue;
        }
        if (rabbits[i - 1].d == 'L') {
            move(i, rabbits[i - 1].x + 1);
            continue;
        }
        assert(rabbits[i - 1].x == rabbits[i].x - 1);
    }


    cout << ans << endl;
}
