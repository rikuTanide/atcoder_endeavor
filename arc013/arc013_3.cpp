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

struct Habanero {
    int y, x, z;
};

struct Tofu {
    int x, y, z;
    vector<Habanero> habaneros;

    int up() {
        int ma = 0;
        for (Habanero habanero : habaneros) {
            cmax(ma, habanero.y);
        }

        return (y - 1) - ma;
    }

    int down() {
        int mi = INT_MAX;
        for (Habanero habanero : habaneros) {
            cmin(mi, habanero.y);
        }
        return mi;
    }

    int right() {
        int ma = 0;
        for (Habanero habanero : habaneros) {
            cmax(ma, habanero.x);
        }

        return (x - 1) - ma;
    }

    int left() {
        int mi = INT_MAX;
        for (Habanero habanero : habaneros) {
            cmin(mi, habanero.x);
        }
        return mi;
    }


    int front() {
        int ma = 0;
        for (Habanero habanero : habaneros) {
            cmax(ma, habanero.z);
        }
        return (z - 1) - ma;
    }


    int back() {
        int mi = INT_MAX;
        for (Habanero habanero : habaneros) {
            cmin(mi, habanero.z);
        }
        return mi;
    }

};

int main() {
    int n;
    cin >> n;

    vector<Tofu> tofus(n);
    rep(i, n) {

        Tofu tofu;
        cin >> tofu.x >> tofu.y >> tofu.z;

        int m;
        cin >> m;
        tofu.habaneros = vector<Habanero>(m);
        rep(j, m) {
            Habanero habanero;
            cin >> habanero.x >> habanero.y >> habanero.z;
            tofu.habaneros[j] = habanero;
        }
        tofus[i] = tofu;
    }

    ll k = 0;
    for (Tofu &t : tofus) {
        k ^= t.up();
        k ^= t.down();
        k ^= t.right();
        k ^= t.left();
        k ^= t.front();
        k ^= t.back();
    }

    cout << (k == 0 ? "LOSE" : "WIN") << endl;


}
