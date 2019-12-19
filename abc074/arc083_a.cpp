#include <bits/stdc++.h>
#include <cmath>


#include <assert.h>    // LON
#include <math.h>    // sqrt()


using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX;
const ll MINF = -10e10;
//const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;


int main() {
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;

    auto canSolve = [&](int a, int b, int c, int d) {
        int sugar = (c * C) + (d * D);
        int water = (a * A * 100) + (b * B * 100);
        return water * E >= 100 * sugar;
    };

    auto concentration = [&](int a, int b, int c, int d) {
        int sugar = (c * C) + (d * D);
        int water = (a * A * 100) + (b * B * 100);
        return (100.0 * sugar) / (water + sugar);
    };

    double par = 0;
    int sugar = 0, sugar_water = 0;
    for (int a = 0; a * A * 100 <= F; a++) {
        int aw = a * A * 100;
        for (int b = 0; aw + (b * B * 100) <= F; b++) {
            int bw = b * B * 100;
            for (int c = 0; aw + bw + (c * C) <= F && canSolve(a, b, c, 0); c++) {
                int cs = c * C;
                for (int d = 0; aw + bw + cs + (d * D) <= F && canSolve(a, b, c, d); d++) {
                    int p = concentration(a, b, c, d);
                    if (p > par) {
                        par = p;
                        sugar = (c * C) + (d * D);
                        sugar_water = (a * A * 100) + (b * B * 100) + (c * C) + (d * D);
                    }
                }
            };
        }
    }

    cout << sugar_water << ' ' << sugar << endl;

}