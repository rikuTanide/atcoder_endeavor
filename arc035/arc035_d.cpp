#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const long double EPS = 1e-9;

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

std::istream &operator>>(std::istream &in, set<char> &o) {
    string a;
    in >> a;
    for (char c : a) o.insert(c);
    return in;
}

std::istream &operator>>(std::istream &in, queue<int> &o) {
    ll a;
    in >> a;
    o.push(a);
    return in;
}

bool contain(set<char> &s, char a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;


map<ll, int> factorize(ll n) {
    map<ll, int> res;

    for (ll i = 2; i * i <= n; i++) {
        if (n % i != 0) {
            continue;
        }
        res[i] = 0;
        while (n % i == 0) {
            n /= i;
            res[i]++;
        }
    }

    if (n != 1) res[n] = 1;
    return res;
}


ll comb(ll l, ll r) {
    map<ll, ll> factors;
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

    for (auto e : factors) {

        for (int k = 0; k < e.second; k++) {
            s *= e.first;
        }
    }

    return s;
}

double combf(ll l, ll r, vector<double> &facts) {
    double la = facts[l];
    double lr = facts[l - r ];
    double d = facts[r];

    return la - lr - d;

}

const double e =  2.7182818284590452;

int main() {
    int n;
    cin >> n;

    vector<P> checkpoints(n);
    rep(i, n) cin >> checkpoints[i].first >> checkpoints[i].second;

    vector<double> facts(pow(10, 7));
    facts[0] = 0;
    facts[1] = 0;
    rep(i, pow(10, 6.5)) {
        if (i <= 1) continue;
        facts[i] = facts[i - 1] + log(i);
    }

    int q;
    cin >> q;
    rep(_, q) {
        int t;
        cin >> t;

        if (t == 1) {
            int k, a, b;
            cin >> k >> a >> b;
            k--;
            checkpoints[k] = P(a, b);
        } else {
            int l1, r1, l2, r2;
            cin >> l1 >> r1 >> l2 >> r2;

            l1--;
            r1--;
            l2--;
            r2--;

            auto f = [&](int l, int r) {
                double ans = 0;
                for (int i = l; i < r; i++) {
                    ll h = abs(checkpoints[i].first - checkpoints[i + 1].first);
                    ll w = abs(checkpoints[i].second - checkpoints[i + 1].second);

//                    ll now = comb(h + w, w);
                    double nf = combf(h + w, w, facts);
                    ans += nf;
//                    double f = pow(e, nf);
//
//                    ans *= now;
                }
                return ans;
            };

            ll a = f(l1, r1);
            ll b = f(l2, r2);

            string ans = a > b ? "FIRST" : "SECOND";
            cout << ans << endl;
        }

    }

}
