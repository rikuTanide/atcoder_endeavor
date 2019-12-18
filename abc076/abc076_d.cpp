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
//typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = 10e15;
const ll MINF = -10e10;
const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;

int main() {

    int n;
    cin >> n;

    vector<int> over_lines;

    {
        vector<int> ts(n);
        vector<int> vs(n);
        rep(i, n) {
            cin >> ts[i];
        }
        rep(i, n) {
            cin >> vs[i];
        }

        int ts_sum = 0;
        for (int i : ts) {
            ts_sum += i;
        }
        over_lines.resize(ts_sum + 2, 0);

        int index = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < ts[i]; j++) {
                over_lines[index] = vs[i];
                index++;
            }
        }

    }
    rep(i, 30) {
        for (int i = 1; i < over_lines.size(); i++) {
            over_lines[i] = min(over_lines[i], over_lines[i - 1] + 1);
        }

        for (int i = over_lines.size() - 2; i >= 0; i--) {
            over_lines[i] = min(over_lines[i], over_lines[i + 1] + 1);
        }
    }
    ll ans = 0;

    for (int i = 1; i < over_lines.size() - 1; i++) {
        int a = over_lines[i - 1];
        int b = over_lines[i];
        int c = over_lines[i + 1];
        assert(b > 0);
        assert(abs(a - b) <= 1);
        assert(abs(b - c) <= 1);
        if (a == b && b == c) {
            ans += b * 100ll;
        } else if (a > b && b < c) {
            ans += b * 100ll;
        } else if ((a > b && b == c) || (a == b && b < c)) {
            ans += b * 100ll;
        } else if ((a == b && b > c) || (a < b && b == c)) {
            ans += ((b - 1) * 100ll) + 50;
        } else if (a < b && b > c) {
            ans += ((b - 1) * 100ll) + 25;
        } else if ((a < b && b < c) || (a > b && b > c)) {
            ans += ((b - 1) * 100ll) + 50;
        } else {
            ans += b * 100ll;
        }
    }

    cout << ((double) ans) / 100 << endl;
}
