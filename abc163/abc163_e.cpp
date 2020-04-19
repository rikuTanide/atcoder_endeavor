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
const int mod = 1000000007;


struct Infant {
    ll index;
    ll active;
};

queue<P> enu(int n) {
    queue<P> q;
    for (int i = 0; i < n; i++) {
        for (int x = 0; x <= i; x++) {
            q.push({x, i - x});
        }
    }
    return q;
}

int main() {
    int n;
    cin >> n;

    vector<Infant> infants(n);
    rep(i, n) infants[i].index = i;
    rep(i, n) cin >> infants[i].active;

    sort(infants.rbegin(), infants.rend(), [&](Infant i, Infant j) { return i.active < j.active; });

    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
    queue<P> q = enu(n);


    while (!q.empty()) {
        P p = q.front();
        q.pop();
        ll i = p.first + p.second;
        Infant infant = infants[i];
        ll from = dp[p.first][p.second];

        ll to_l = abs(infant.index - p.first) * infant.active;
        ll to_r = abs(infant.index - (n - p.second - 1)) * infant.active;

        cmax(dp[p.first + 1][p.second], from + to_l);
        cmax(dp[p.first][p.second + 1], from + to_r);
    }

    vector<ll> candidate;
    rep(i, n) {
        ll now = *max_element(dp[i].begin(), dp[i].end());
        candidate.push_back(now);
    }
    ll ans = *max_element(candidate.begin(), candidate.end());
    cout << ans << endl;

}

//ll ans = 0;
//rep(i, n) {
//Infant infant = target[i];
//ll diff = abs(infant.index - i);
//ll now = infant.active * diff;
//ans += now;
//}
//return ans;