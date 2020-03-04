#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
//using namespace boost::multiprecision;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<double, double> P;
const ll INF = 1e15;
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

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
const int mod = 1000000007;
//const ll mod = 1e10;
typedef priority_queue<string, vector<string>, greater<string> > PQ_ASK;


map<ll, ll> factorize(ll n) {
    map<ll, ll> res;
    res[1] = 1;

    for (ll i = 2; i * i <= n; i++) {
        if (n % i != 0) {
            continue;
        }
        res[i] = 0;
        while (n % i == 0) {
            n /= i;
            res[i]++;
        }
    }

    if (n != 1) res[n] = 1;
    return res;

}

int main() {
    ll a, b;
    cin >> a >> b;

    map<ll, ll> f1 = factorize(a), f2 = factorize(b);

    int i = 0;
    for (auto e : f1) {
        if (f2.find(e.first) != f2.end()) i++;
    }
    cout << i << endl;

}
