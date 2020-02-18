#include <bits/stdc++.h>
#include <cmath>

//using namespace boost::multiprecision;
using namespace std;
typedef long long ll;
//typedef unsigned long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
typedef pair<int, int> P;
//typedef pair<ll, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX / 100;
//const ll INF = (1ll << 31) - 1;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
//typedef pair<int, int> P;
//typedef pair<double, double> P;

bool contain(set<string> &s, string a) { return s.find(a) != s.end(); }

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
const int mod = 1000000007;
//const ll mod = 1e10;
typedef priority_queue<long long, vector<long long>, greater<long long> > PQ_ASK;

vector<pair<ll, int >> factorize(ll n) {
    vector<pair<ll, int >> res;

    for (ll i = 2; i * i <= n; i++) {
        if (n % i != 0) {
            continue;
        }
        res.emplace_back(i, 0);
        while (n % i == 0) {
            n /= i;
            res.back().second++;
        }
    }

    if (n != 1) res.emplace_back(n, 1);
    return res;

}

ll comb(ll l, ll r) {
    vector<ll> factors(50);
    for (ll j = l; j > (l - r); j--) {
        auto fs = factorize(j);
        for (auto f : fs) {
            factors[f.first] += f.second;
        }
    }

    for (ll j = 1; j <= r; j++) {
        auto fs = factorize(j);
        for (auto f : fs) {
            factors[f.first] -= f.second;
        }
    }

    ll s = 1;

    for (int j = 1; j < 50; j++) {
        for (int k = 0; k < factors[j]; k++) {
            s *= j;
        }
    }

    return s;

}


int main() {
    int n;


    cin >> n;
    int odd = 0, b2 = 0, b4 = 0;
    rep(i, n) {
        ll a;
        cin >> a;
        if (a % 4 == 0) b4++;
        else if (a % 2 == 0) b2++;
        else odd++;
    }
    if (b2 == 1) {
        odd++;
    }

    if (b4 == 0 && odd > 0) {
        cout << "No" << endl;
    } else if (odd - 1 > b4) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }


}

