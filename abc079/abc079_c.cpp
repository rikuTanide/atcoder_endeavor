#include <bits/stdc++.h>
#include <cmath>

using namespace std;
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
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

struct N {
    int index, number;
    char operation;
};


int main() {
    char _a, _b, _c, _d;
    cin >> _a >> _b >> _c >> _d;
    int a = _a - '0';
    vector<int> nums = {
            _b - '0',
            _c - '0',
            _d - '0',
    };

    for (int i = 0; i < (1 << 3); i++) {
        int now = a;
        for (int j = 0; j < 3; j++) {
            int k = (i >> j) & 1;
            int l = ((k + 1) & 0b10) - 1;
            int m = nums[j] * l;
            now += m;
        }
        if (now == 7) {
            cout << a;
            for (int j = 0; j < 3; j++) {
                int k = (i >> j) & 1;
                int l = ((k + 1) & 0b10) - 1;
                int m = nums[j] * l;
                printf("%+d", m);
            }

            cout << "=7" << endl;
            return 0;
        }
    }

}