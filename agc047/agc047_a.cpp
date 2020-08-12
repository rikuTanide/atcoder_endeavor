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

int main() {
    int n;
    cin >> n;

    auto get_ll = [&]() {
        vector<ll> v(n);

        rep(i, n) {
            string s;
            cin >> s;

            if (find(s.begin(), s.end(), '.') == s.end()) s += ".0";

            while (distance(find(s.begin(), s.end(), '.'), s.end()) <= 9) {
                s += '0';
            }

            ll a = 0;
            for (char c : s) {
                if (c == '.') continue;
                ll k = c - '0';
                a *= 10;
                a += k;
            }

            v[i] = a;
        }
        return v;
    };

    vector<ll> v = get_ll();

    auto f = [&](int k) -> vector<int> {
        vector<int> res(n);
        rep(i, n) {
            ll t = v[i];
            int l = 0;
            while (t % k == 0) {
                l++;
                t /= k;
            }
            res[i] = l;
        }
        return res;
    };

    vector<int> tows = f(2);
    vector<int> fives = f(5);

    vector<P> pairs;
    rep(i, n) {
        pairs.push_back(P(tows[i], fives[i]));
    }
    map<P, int> counts;
    for (P p : pairs) counts[p]++;
    ll ans = 0;

    auto check = [&](P a, P b) -> bool {
        return a.first + b.first >= 18 && a.second + b.second >= 18;
    };

    for (auto e1 : counts) {
        for (auto e2 : counts) {
            if (check(e1.first, e2.first))ans += e1.second * e2.second;
        }
    }

    auto check_one = [&](P a) -> bool {
        return a.first >= 9 && a.second >= 9;
    };
    for (P p : pairs) {
        if (check_one(p)) ans--;
    }
    ans /= 2;


    cout << ans << endl;

}
