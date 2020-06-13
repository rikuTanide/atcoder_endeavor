#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

const double PI = 3.14159265358979323846;
using namespace std;
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

bool contain(set<char> &s, char a) { return s.find(a) != s.end(); }

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//const ll mod = 1e10;
typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

//    ifstream is("/home/riku/Downloads/N100000_0.in");

    int n;
    cin >> n;
//    is >> n;

    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
//    rep(i, n) is >> a[i];
    rep(i, n) cin >> b[i];
//    rep(i, n) is >> b[i];

    int sum = 0;

    rep(i, n) {
        rep(j, n) {
            int k = a[i] + b[j];
            sum ^= k;
        }
    }

    cout << sum << endl;

}