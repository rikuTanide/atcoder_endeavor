#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

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

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;


int main() {
    int all, n, m;
    cin >> all >> n >> m;

    vector<ll> lines(n);
    rep(i, n) cin >> lines[i];

    vector<P> query(m);
    rep(i, m) cin >> query[i].first >> query[i].second;

    sort(lines.begin(), lines.end());
    vector<ll> between(n - 1);
    rep(i, n - 1) between[i] = lines[i + 1] - lines[i] - 1;

    sort(between.begin(), between.end());

    vector<ll> between_sum;
    between_sum.push_back(0);
    rep(i, n - 1) between_sum.push_back(between_sum[i] + between[i]);

    for (P q : query) {
        ll now = n;
        ll x = q.first;
        ll y = q.second;
        now += min(lines[0] - 1, q.first);
        now += min(all - lines[n - 1], y);
        ll xy = x + y;
        auto it = upper_bound(between.begin(), between.end(), xy);
        int i = distance(between.begin(), it);
        now += between_sum[i] + (n - i - 1) * xy;
        cout << now << endl;

    }

}

