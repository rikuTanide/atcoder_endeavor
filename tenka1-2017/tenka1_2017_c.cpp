#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
//using namespace boost::multiprecision;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
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
typedef priority_queue<long long, vector<long long>, greater<long long> > PQ_ASK;

int check(ll n, ll x, ll y) {
    ll bunshi = n * x * y;
    ll bunbo = x * y * 4 - n * (y + x);
    if (bunbo == 0) return -1;
    if (bunshi % bunbo != 0) return -1;
    ll ans = bunshi / bunbo;
    if (ans <= 0) return -1;
    return ans;
}

void test(double n, double x, double y, double now) {
    cout << (4 / n) << endl;
    cout << (1 / x) + (1 / y) + (1 / now) << endl;
}

int main() {

    ll n;
    cin >> n;

    for (ll x = 1; x <= 3500; x++) {
        for (ll y = 1; y <= 3500; y++) {
            ll now = check(n, x, y);
            if (now == -1) continue;
            printf("%d %d %d\n", x, y, now);
//            test(n, x, y, now);
            ret();
        }
    }


}