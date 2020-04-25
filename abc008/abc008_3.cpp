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
    int n;
    cin >> n;
    vector<ll> coins(n);
    rep(i, n) cin >> coins[i];
    sort(coins.begin(), coins.end());

    vector<int> f_count(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ll a = coins[i];
            ll b = coins[j];
            assert(b >= a);
            if (b % a == 0) f_count[j]++;
        }
    }

    vector<double> fact(102);
    fact[0] = 0;
    fact[1] = 1;
    rep(i, 102) {
        if (i <= 1) continue;
        fact[i] = fact[i - 1] * i;
    }


    double sum = 0;
    for (int i : f_count) {
        if (i % 2 == 0) {
            double now = double(i + 2) / (2 * i + 2);
            sum += now;
        } else {
            double now = (1.0 / 2);
            sum += now;
        }
    }
    printf("%.20f", sum);
}

