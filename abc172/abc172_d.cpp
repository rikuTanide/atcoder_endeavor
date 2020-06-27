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

vector<ll> Eratosthenes(int N) {
    int arr[N];

    for (int i = 0; i < N; i++) {
        arr[i] = 1;
    }
    for (int i = 2; i < sqrt(N); i++) {
        if (arr[i]) {
            for (int j = 0; i * (j + 2) < N; j++) {
                arr[i * (j + 2)] = 0;
            }
        }
    }

    for (int i = 2; i < N; i++) {
        if (arr[i]) {
            //cout << i << endl;
        }
    }
    vector<ll> ans;
    for (int i = 2; i < N; i++) {
        if (arr[i]) ans.push_back(i);
    }
    return ans;
}


map<ll, int> factorize(ll n, vector<ll> &facts) {
    map<ll, int> res;

    for (ll i  : facts) {
        if (i * i > n)break;

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

ll f(ll k, vector<ll> &facts) {
    auto fs = factorize(k, facts);
    ll sum = 1;
    for (auto e : fs) {
        ll now = e.second + 1;
        sum *= now;
    }
    return sum;
}

int main() {
    ll n;
    cin >> n;

    vector<ll> facts = Eratosthenes(n + 1);

    ll sum = 0;
    for (int k = 1; k <= n; k++) {
        sum += (f(k, facts) * k);
    }
    cout << sum << endl;
}
