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

// 一段減らす
vector<int> sub(vector<int> &v) {
    if (v.size() == 1) return v;
    vector<int> v2(v.size() - 1);
    rep(i, v.size() - 1) {
        v2[i] = abs(v[i] - v[i + 1]);
    }
    return v2;
}

// 半分にする
vector<int> tournament(vector<int> &v) {
    vector<int> next;
    for (int i = 0; i < v.size(); i += 2) {
        int a = abs(v[i] - v[i + 1]);
        next.push_back(a);
    }
    return next;
}

// 偶数なら半分にする
// 奇数なら一段減らしてから半分にする
int solv(vector<int> v) {
    while (v.size() != 1) {
        if (v.size() % 2 == 0) {
            v = tournament(v);
        } else {
            v = sub(v);
        }
    }
    return v.front();
}

int main() {
    int n;
    cin >> n;
    vector<char> u(n);
    rep(i, n)cin >> u[i];
    vector<int> v(n);
    rep(i, n) v[i] = u[i] - '0';

    v = sub(v);
    v = sub(v);
    v = sub(v);
    v = sub(v);

    cout << solv(v) << endl;

}
