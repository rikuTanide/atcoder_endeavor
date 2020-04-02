#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep(i, n) for (ll i = 0; i < (n); ++i)
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

#include <iostream>
#include <vector>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<ll> numbers(n);
    rep(i, n) cin >> numbers[i];

    sort(numbers.begin(), numbers.end());

    vector<P> build;

    queue<ll> plus, minus;
    rep(i, n) {
        if (i == 0) {
            minus.push(numbers[i]);
        } else if (i == n - 1) {
            plus.push(numbers[i]);
        } else {
            if (numbers[i] < 0) minus.push(numbers[i]);
            else plus.push(numbers[i]);
        }
    }

    while (plus.size() > 1) {
        ll pf = plus.front(), mf = minus.front();
        plus.pop();
        minus.pop();
        minus.push(mf - pf);
        build.emplace_back(mf, pf);
    }
    ll ans;
    while (!minus.empty()) {
        ll pf = plus.front(), mf = minus.front();
        plus.pop();
        minus.pop();
        ans = pf - mf;
        plus.push(ans);
        build.emplace_back(pf, mf);
    }
    cout << ans << endl;

    for (P p : build) {
        printf("%lld %lld\n", p.first, p.second);
    }
}
