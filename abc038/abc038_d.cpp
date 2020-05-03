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

struct Box {
    int w, h;
};

std::istream &operator>>(std::istream &in, Box &o) {
    cin >> o.w >> o.h;
    return in;
}

bool in(Box &b1, Box &b2) {
    if (b1.w > b2.w && b1.h > b2.h) return true;
    return false;
}

int rec(int i, int n, vector<Box> &boxes, vector<int> &dp) {
    if (dp[i] != -1) return dp[i];
    int now = 0;
    rep(j, n) {
        if (!in(boxes[i], boxes[j])) continue;
        cmax(now, rec(j, n, boxes, dp));
    }
    dp[i] = now + 1;
    return now + 1;
}

int main() {
    int n;
    cin >> n;
    vector<Box> boxes(n);
    rep(i, n) cin >> boxes[i];

    vector<int> dp(n, -1);
    rep(i, n) dp[i] = rec(i, n, boxes, dp);

    cout << *max_element(dp.begin(), dp.end()) << endl;
}
