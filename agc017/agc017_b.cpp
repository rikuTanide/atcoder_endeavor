#include <bits/stdc++.h>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

std::istream &operator>>(std::istream &in, set<ll> &o) {
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

//const ll mod = 1e10;
//typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;

// b-=a, a = 0としていい
// プラスマイナス対称なので、正の場合だけ考えればいい

// n >= c * 2 / (d - c) なら、くっつくから最大値と最小値だけ考えればいい

// d * n < b なら絶対ムリ

// bを超える (c + d)の倍数の中で一番小さいものは
// (b + (c+d) - 1) / (c+b) * (c+b)
// 上から上ー（d-c）* 上ならok


bool solve() {
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    b -= a;
    a = 0;
    b = abs(b);
    if (d * n < b) {
        return false;
    }

    __throw_runtime_error("mada");

}

int main() {

    string ans = solve() ? "YES" : "NO";
    cout << ans << endl;


/*
    vector<set<P>> k;

    k.push_back({{a, a}});

    rep(i, n) {
        set<P> next;
        for (P p : k.back()) {
            next.insert({p.first + c, p.second + d});
            next.insert({p.first - d, p.second - c});
        }
        k.push_back(next);
    }

    rep(i, n + 1) {
        ll up = i * d;
        for (P p : k[i]) {
            printf("%lld %lld %lld %lld\n", p.first, p.second, up + p.first, up + p.second);
        }
        cout << endl;
    }

*/


}