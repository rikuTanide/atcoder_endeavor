#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
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


int main() {
    ll n, k;
    cin >> n >> k;

    vector<ll> numbers(n), values(n);
    rep(i, n) cin >> numbers[i] >> values[i];

//    cout << bitset<8>(k) << endl;
//    rep(i, n) cout << bitset<8>(numbers[i]) << ' ' << values[i] << endl;

    vector<ll> candidate;
    {
        ll sum = 0;
        rep(i, n) {
            if ((k | numbers[i]) == k) sum += values[i];
        }
        candidate.push_back(sum);
    }

    rep(i, 35) {
        bool d = (k >> i) & 1;
        if (!d) continue;

        ll sum = 0;

        ll target = k >> (i + 1);
        rep(j, n) {
            ll l = numbers[j];
            bool b = ((l >> i) & 1);
            if (b) continue;
            ll c = (l >> (i + 1));
            if ((target | c) != target) continue;
            sum += values[j];
        }
        candidate.push_back(sum);
    }

    // 0

    cout << *max_element(candidate.begin(), candidate.end()) << endl;
}


