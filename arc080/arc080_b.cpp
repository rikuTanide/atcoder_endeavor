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

int main() {
    int h, w;
    cin >> h >> w;

    int n;
    cin >> n;

    queue<int> colors;
    rep(i, n) {
        int a;
        cin >> a;
        rep(j, a)colors.push(i);
    }

    vector<vector<int>> picture(h, vector<int>(w, 0));

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            picture[i][j] = colors.front();
            colors.pop();
        }
    }

    rep(i, h) {
        if (i % 2 == 0) continue;
        reverse(picture[i].begin(), picture[i].end());
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << picture[i][j] + 1;
        }
        cout << endl;
    }


}