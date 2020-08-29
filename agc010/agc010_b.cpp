#include <bits/stdc++.h>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
typedef pair<double, ll> P;
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

int main() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    rep(i, n)cin >> v[i];

    ll par = n * (n + 1) / 2;
    ll all = accumulate(v.begin(), v.end(), 0ll);
    if (all % par != 0) {
        cout << "NO" << endl;
        ret();
    }

    ll turn = all / par;


    vector<ll> diff(n);
    rep(i, n) diff[i] = v[(i + 1) % n] - v[i] - turn;

    for (ll g : diff) {
        if (g <= 0 && (-g) % n == 0) continue;
        cout << "NO" << endl;
        ret();
    }

    cout << "YES" << endl;

}