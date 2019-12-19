#include <bits/stdc++.h>
#include <cmath>


#include <assert.h>    // LON
#include <math.h>    // sqrt()


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

class Field {
public:
    vector<vector<char>> field;

    Field(int h, int w) {
        field = vector<vector<char>>(w, vector<char>(h));
    }

    char get(int x, int y) {
        if (x == -1 || y == -1) {
            return '.';
        }
        if (x == field.size() || y == field[x].size()) {
            return '.';
        }
        return field[x][y];
    }

};


int main() {
    int h, w;
    cin >> h >> w;
    Field field(h, w);
    rep(y, h) rep(x, w) {
            cin >> field.field[x][y];
        }

    rep(y, h) {
        rep(x, w) {
            if (field.get(x, y) == '#') {
                cout << '#';
                continue;
            }

            int now = 0;
            if (field.get(x - 1, y - 1) == '#') {
                now++;
            }
            if (field.get(x, y - 1) == '#') {
                now++;
            }
            if (field.get(x + 1, y - 1) == '#') {
                now++;
            }

            if (field.get(x - 1, y) == '#') {
                now++;
            }
            if (field.get(x + 1, y) == '#') {
                now++;
            }

            if (field.get(x - 1, y + 1) == '#') {
                now++;
            }
            if (field.get(x, y + 1) == '#') {
                now++;
            }
            if (field.get(x + 1, y + 1) == '#') {
                now++;
            }
            cout << now;
        }
        cout << endl;
    }
}
