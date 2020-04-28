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


double dfs(int x, vector<double> &fact, vector<double> &dp) {
    if (dp[x] >= 0) return dp[x];

    auto comb = [&](double g, double c, double p) {
        return fact[g + c + p] / fact[g] / fact[c] / fact[p];
    };

    vector<double> per(128);
    rep(g, x + 1) {
        rep(c, x + 1 - g) {
            int p = x - g - c;
            vector<int> te;
            if (g != 0)te.push_back(g);
            if (c != 0)te.push_back(c);
            if (p != 0)te.push_back(p);
            int rare = *min_element(te.begin(), te.end());

            switch (count(te.begin(), te.end(), rare)) {
                case 1:
                case 2:
                    per[rare] += comb(g, c, p);
                    break;
                case 3:
                    per[x] += comb(g, c, p);
                    break;
            }
        }
    }

    double zen = accumulate(per.begin(), per.end(), 0.0);
    for (auto &&a :per)a /= zen;
    double res = 1;
    rep(i, x) if (i != 0) res += per[i] * dfs(i, fact, dp);
    res /= (1 - per[x]);
    dp[x] = res;
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<double> fact(101);
    rep(i, 101) {
        if (i == 0) fact[0] = 1;
        else fact[i] = fact[i - 1] * i;
    }

    vector<double> dp(101, -1);
    dp[1] = 0;
    double ans = dfs(n, fact, dp);

    printf("%.20f\n", ans);
}
