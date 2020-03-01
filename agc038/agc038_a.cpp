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

    a = min(a, w - a);
    b = min(b, h - b);

    vector<int> horizontal_budget(w), vertical_budget(h);
    // その行に含まれる0の個数 a = vertical
    // その列に含まれる0の個数 b = horizontal
    rep(i, h) vertical_budget[i] = a;
    rep(i, w) horizontal_budget[i] = b;

    assert(w > 1);
    assert(h > 1);

    vector<vector<int>> matrix(h, vector<int>(w, 0));

    rep(y, h) {
        rep(x, w) {
            if (vertical_budget[y] > 0 && horizontal_budget[x] > 0) {
                vertical_budget[y]--;
                horizontal_budget[x]--;
                matrix[y][x] = 1;
            }
        }
    }

    rep(y, h) {
        if (vertical_budget[y] != 0) {
            cout << "No" << endl;
            ret();
        }
    }
    rep(x, w) {
        if (horizontal_budget[x] != 0) {
            cout << "No" << endl;
            ret();
        }
    }


    rep(y, h) {
        rep(x, w) {
            cout << matrix[y][x];
        }
        cout << endl;
    }
}
