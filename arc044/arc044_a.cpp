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

bool is_prime(ll n) {
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

bool is_last5(ll n) {
    ll k = n % 10;
    if (k % 2 == 0) return false;
    if (k == 5) return false;
    return true;
}

bool is_sum3(ll n) {
    ll sum = 0;

    while (n > 0) {
        ll a = n % 10;
        n /= 10;
        sum += a;
    }
    return sum % 3;

}

int main() {
    ll n;
    cin >> n;
    if (n == 1) {
        cout << "Not Prime" << endl;
    } else if (is_prime(n)) {
        cout << "Prime" << endl;
    } else if (!is_last5(n)) {
        cout << "Not Prime" << endl;
    } else if (is_sum3(n)) {
        cout << "Not Prime" << endl;
    } else {
        cout << "Not Prime" << endl;
    }

}