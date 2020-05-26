#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<int> &o) {
    int a;
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

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;

int main() {
    int w, h;
    cin >> w >> h;

    int n;
    cin >> n;

    vector<P> machines(n);
    rep(i, n) cin >> machines[i].second >> machines[i].first, machines[i].first--, machines[i].second--;


    vector<int> arr(n);
    rep(i, n)arr[i] = i;

    int ans = 0;
    do {

        vector<vector<bool>> board(h, vector<bool>(w, true));

        int now = 0;
        for (int i : arr) {

            P p = machines[i];
            board[p.first][p.second] = false;
            now++;

            for (int x = p.second + 1; x < w && board[p.first][x]; x++) {
                board[p.first][x] = false;
                now++;
            }
            for (int x = p.second - 1; x >= 0 && board[p.first][x]; x--) {
                board[p.first][x] = false;
                now++;
            }
            for (int y = p.first - 1; y >= 0 && board[y][p.second]; y--) {
                board[y][p.second] = false;
                now++;
            }
            for (int y = p.first + 1; y < h && board[y][p.second]; y++) {
                board[y][p.second] = false;
                now++;
            }
        }

        cmax(ans, now);

    } while (std::next_permutation(arr.begin(), arr.end()));

    cout << ans << endl;
}