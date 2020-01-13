#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

//#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef pair<int, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;
const double PI = acos(-1);

double f(double t, double a, double b, double c) {
    return a * t + b * sin(c * t * PI);
}

int main() {


    double a, b, c;
    cin >> a >> b >> c;

    double ceil = 100000000.0;
    double floor = 0.0;

    for (int i = 0; i < 100000; i++) {
        double mid = (ceil + floor) / 2;
        double nf = f(mid, a, b, c);
        if (nf > 100) {
            ceil = mid;
        } else {
            floor = mid;
        }
    }

    printf("%0.20f\n", floor);

}