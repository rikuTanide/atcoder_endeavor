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

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

void recursive_comb(vector<int> &indexes, int s, int rest, std::function<void(vector<int> &)> f) {
    if (rest == 0) {
        f(indexes);
    } else {
        if (s < 0) return;
        recursive_comb(indexes, s - 1, rest, f);
        indexes[rest - 1] = s;
        recursive_comb(indexes, s - 1, rest - 1, f);
    }
}

// nCkの組み合わせに対して処理を実行する
void foreach_comb(int n, int k, function<void(vector<int> &)> f) {
    vector<int> indexes(k, 0);
    recursive_comb(indexes, n - 1, k, f);
}

struct Chocolate {
    int from, to;
    ll happy;
};

std::istream &operator>>(std::istream &in, Chocolate &o) {
    cin >> o.from >> o.to >> o.happy;
    o.from--;
    o.to--;
    return in;
}

int check(vector<int> &indexes, int q, int m, vector<vector<Chocolate>> &has) {
    vector<int> mens(m);
    for (int g: indexes) {
        for (Chocolate &c : has[g]) {
            mens[c.to] += c.happy;
        }
    }
    sort(mens.rbegin(), mens.rend());
    ll sum = accumulate(mens.begin(), mens.begin() + q, 0ll);
    return sum;
}

int main() {
    int n, m, p, q, r;

    cin >> n >> m >> p >> q >> r;

    vector<Chocolate> chocoaltes(r);
    rep(i, r) cin >> chocoaltes[i];

    vector<vector<Chocolate>> has(n);
    for (Chocolate c : chocoaltes) has[c.from].push_back(c);

    ll ans = 0;
    foreach_comb(n, p, [&](vector<int> &indexes) {
        ll now = check(indexes, q, m, has);
        cmax(ans, now);
    });
    cout << ans << endl;
}
