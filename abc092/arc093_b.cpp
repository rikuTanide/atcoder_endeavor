#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = 10e15;
const ll MINF = -10e10;
//const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;


int main() {
    int a, b;
    cin >> a >> b;

    int width = 95; //100 * 100;
    int cells = width * (width / 5);

    vector<bool> whites(cells, true);
    vector<bool> blacks(cells, false);

    for (int i = 1; i < a; i++) {
        blacks[i * 2] = true;
    }
    for (int i = 1; i < b; i++) {
        whites[i * 2] = false;
    }

    reverse(blacks.begin(), blacks.end());

    cout << ((width / 5) * 2 * 2) << ' ' << width + 2 << endl;

    for (int i = 0; i < cells; i++) {
        if (i % width == 0) {
            for (int j = 0; j < width + 2; j++) {
                cout << '.';
            }
            cout << endl;
            cout << '.';
        }
        if (whites[i] == true) {
            cout << '.';
        } else {
            cout << '#';
        }
        if (i % width == width - 1) {
            cout << '.' << endl;

        }
    }

    for (int i = 0; i < cells; i++) {
        if (i % width == 0) {
            cout << '#';
        }
        if (blacks[i] == true) {
            cout << '.';
        } else {
            cout << '#';
        }
        if (i % width == width - 1) {
            cout << '#' << endl;
            for (int j = 0; j < width + 2; j++) {
                cout << '#';
            }
            cout << endl;
        }
    }

}