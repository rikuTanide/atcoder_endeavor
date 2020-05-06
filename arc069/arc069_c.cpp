#include <bits/stdc++.h>


using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<string> &o) {
    string a;
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

typedef pair<ll, ll> P;

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;
typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;


int main() {
    int n;
    cin >> n;

    vector<ll> rocks(n);
    rep(i, n) cin >> rocks[i];

    vector<int> s;

    while (count(rocks.begin(), rocks.end(), 0) < n) {
        int ma = *max_element(rocks.begin(), rocks.end());
        auto mai = find(rocks.begin(), rocks.end(), ma);
        s.push_back(distance(rocks.begin(), mai) + 1);
        reverse(rocks.begin(), rocks.end());
        auto it = find(rocks.begin(), rocks.end(), ma);
        (*it)--;
        reverse(rocks.begin(), rocks.end());
    }

    vector<int> ans(n + 1);
    for (int i : s) if (i <= n) ans[i]++;

    rep(i, n) cout << ans[i + 1] << endl;

}
