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


ll gcd(ll x, ll y) {
    if (x > y) swap(x, y);
    ll m = 1;
    while (m != 0) {
        m = y % x;
        y = x;
        x = m;
    }
    return y;
}

ll lcm(ll x, ll y) {
    return x / gcd(x, y) * y;
}

bool check2(vector<ll> &numbers, int n) {
    vector<ll> tows(n);
    rep(i, n) {
        int a = 0;
        ll k = numbers[i];
        while (k % 2 == 0) {
            a++;
            k /= 2;
        }
        tows[i] = a;
    }
    return *max_element(tows.begin(), tows.end()) == *min_element(tows.begin(), tows.end());
}

ll get2(vector<ll> &numbers, int n) {
    ll k = numbers[0];
    ll ans = 1;
    while (k % 2 == 0) {
        ans *= 2;
        k /= 2;
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<ll> numbers(n);
    rep(i, n) cin >> numbers[i];

    rep(i, n) if (numbers[i] % 2 == 1) {
            cout << 0 << endl;
            ret();
        }

    rep(i, n) numbers[i] /= 2;

    if (!check2(numbers, n)) {
        cout << 0 << endl;
        ret();
    }

    ll tow = get2(numbers, n);
    rep(i, n) numbers[i] /= tow;

    ll l = numbers[0];
    rep(i, n) l = lcm(l, numbers[i]);

    ll md = m / tow / l;

    ll ans = (md + 1) / 2;
    cout << ans << endl;


}
