#include <bits/stdc++.h>
//#include "atcoder/all"
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
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

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

const int mod = 1000000007;

// 愚直

//

void straight(vector<P> &v) {


//    ofstream cout("/home/riku/CLionProjects/atcoder/out.txt");

    int y = 0, x = 0;

    auto r = [&]() {
        cout << 'R';
        x++;
    };


    auto l = [&]() {
        cout << 'L';
        x--;
    };

    auto u = [&]() {
        cout << 'U';
        y--;
    };

    auto d = [&]() {
        cout << 'D';
        y++;
    };


    rep(i, 100) {
        int to_y = v[i].first;
        int to_x = v[i].second;

        while (x != to_x) {
            if (x < to_x) r();
            else l();
        }

        while (y != to_y) {
            if (y < to_y) d();
            else u();
        }
        cout << 'I';
    }

    cout << endl;

//    cout << flush;
//    cout.close();

}

int main() {
//    ifstream cin("/home/riku/CLionProjects/atcoder/sampleInput.txt");

    vector<P> v(100);
    for (P &p:v)cin >> p.first >> p.second;

    straight(v);

}