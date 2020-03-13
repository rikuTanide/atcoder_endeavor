#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<int, int> P;
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

double f(double x, double p) {
    return x + p / pow(2, x / 1.5);
}

int main() {
    double p;
    cin >> p;

    double floor = 0, ceil = 10e10;

    rep(i, 1000) {
        double t1 = (2 * floor + ceil) / 3;
        double t2 = (floor + 2 * ceil) / 3;

        if (f(t1, p) <= f(t2, p)) {
            ceil = t2;
        } else if (f(t1, p) >= f(t2, p)) {
            floor = t1;
        } else {
            __throw_runtime_error("konai");
        }
    }


    printf("%.20f\n", f(ceil, p));
}
