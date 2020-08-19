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

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;
struct Mountain {
    int i;
    ll height;
};

vector<int> solve(vector<Mountain> mountains, int n) {
    sort(mountains.rbegin(), mountains.rend(), [](Mountain m1, Mountain m2) {
        //　大きい順、左にある順
        // こうすると、自分より右にある奴はすべてまだ出てきてない
        return P(m1.height, -m1.i) < P(m2.height, -m2.i);
    });

    vector<int> ans(n);
    set<int> used;

    rep(i, n) {
        Mountain mountain = mountains[i];
        int r = [&]() -> int {
            auto it = used.upper_bound(mountain.i);
            if (it == used.end()) {
                int b = n - mountain.i - 1;
                return b;
            }
            int b = (*it) - mountain.i - 1;
            return b;
        }();
        ans[mountain.i] = r;
        used.insert(mountain.i);
    }

    return ans;

}

int main() {
    int n;
    cin >> n;

    vector<Mountain> mountains(n);
    rep(i, n)mountains[i].i = i;
    rep(i, n) cin >> mountains[i].height;

    vector<int> right = solve(mountains, n);
    rep(i, n) mountains[i].i = n - mountains[i].i - 1;
    vector<int> left = solve(mountains, n);
    reverse(left.begin(), left.end());
    vector<int> ans(n);
    rep(i, n) ans[i] = right[i] + left[i];
    for (int i : ans) cout << i << endl;

}
