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
typedef priority_queue<string, vector<string>, greater<string> > PQ_ASK;

int main() {
    int h, w, a, b;
    cin >> h >> w >> a >> b;

    vector<vector<int>> matrix(h, vector<int>(w, 0));

    rep(y, h) {
        rep(x, w) {
            if (y < b && x < a) {
                matrix[y][x] = 0;
            } else if (y < b) {
                matrix[y][x] = 1;
            } else if (x < a) {
                matrix[y][x] = 1;
            } else {
                matrix[y][x] = 0;
            }
        }
    }


    rep(y, h) {
        rep(x, w) {
            cout << matrix[y][x];
        }
        cout << endl;
    }
}
