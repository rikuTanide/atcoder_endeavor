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

int main() {
    int n;
    cin >> n;

    map<ll, int> fs;

    for (int i = 2; i <= n; i++) {
        auto f = factorize(i);
        for (auto e : f) {
            fs[e.first] += e.second;
        }
    }

    vector<int> counts;
    for (auto e : fs) counts.push_back(e.second);

    int m = counts.size();

    int ans = 0;

    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            for (int k = j + 1; k < m; k++) {
                if (counts[i] >= 2 && counts[j] >= 4 && counts[k] >= 4)ans++;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            for (int k = j + 1; k < m; k++) {
                if (counts[i] >= 4 && counts[j] >= 2 && counts[k] >= 4)ans++;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            for (int k = j + 1; k < m; k++) {
                if (counts[i] >= 4 && counts[j] >= 4 && counts[k] >= 2) ans++;
            }
        }
    }


    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            if (counts[i] >= 14 && counts[j] >= 4)ans++;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            if (counts[i] >= 4 && counts[j] >= 14) ans++;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            if (counts[i] >= 2 && counts[j] >= 24) ans++;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            if (counts[i] >= 24 && counts[j] >= 2)ans++;
        }
    }

    for (int i = 0; i < m; i++) {
        if (counts[i] >= 74) ans++;
    }

    cout << ans << endl;
}
