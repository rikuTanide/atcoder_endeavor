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


ll all_gcd(vector<ll> &v) {
    ll now = v.front();
    for (ll l : v) now = __gcd(now, l);
    return now;
}

vector<vector<ll>> all_prime_vec(vector<ll> &v) {
    vector<vector<ll>> ans(v.size());

    rep(i, v.size()) {
        auto f = factorize(v[i]);

        for (auto e : f) {
            if (e.first != 1) {
                ans[i].push_back(e.first);
            }
        }

    }

    return ans;
}

map<ll, int> all_prime_set(vector<vector<ll>> &v) {
    map<ll, int> ans;
    int n = v.size();
    rep(i, n) {
        for (ll l : v[i]) {
            ans[l]++;
        }
    }
    return ans;
}

bool has_pair(vector<vector<ll>> &v, map<ll, int> &s) {
    int n = v.size();
    rep(i, n) {
        for (ll l : v[i]) {
            s[l]--;
            if (s[l] == 0) s.erase(s.find(l));
        }

        for (ll l : v[i]) {
            auto it = s.find(l);
            if (it != s.end()) return true;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<ll> v(n);
    rep(i, n) cin >> v[i];

    ll a = all_gcd(v);

    vector<vector<ll>> a_vec = all_prime_vec(v);
    map<ll, int> a_set = all_prime_set(a_vec);

    bool b = has_pair(a_vec, a_set);

    if (!b) {
        cout << "pairwise coprime" << endl;
    } else if (a == 1) {
        cout << "setwise coprime" << endl;
    } else {
        cout << "not coprime" << endl;
    }

}
