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

/*
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

int main() {
    ll k;
    cin >> k;

    ll sum = 0;
    for (ll a = 1; a <= k; a++) {
        for (ll b = 1; b <= k; b++) {
            for (ll c = 1; c <= k; c++) {
                sum += gcd(gcd(a, b), c);
            }
        }
    }
    cout << sum << endl;
}

 */

int main() {
    int n;
    string s;
    cin >> n >> s;

    ll r = 0, g = 0, b = 0;
    for (char c : s) {
        if (c == 'R') r++;
        else if (c == 'G') g++;
        else if (c == 'B') b++;
    }


    ll all = r * g * b;
    ll none = 0;
    for (int i = 1; i < n; i++) {
        for (int start = 0; start + i + i < n; start++) {
            char j = s[start];
            char k = s[start + i];
            char l = s[start + i + i];
            if (j != k && k != l && l != j) none++;
        }
    }
    cout << all - none << endl;
}