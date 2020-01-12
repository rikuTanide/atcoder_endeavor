#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX;
const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;

ll pow2(ll a, ll b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    ll res = a;
    for (ll i = 1; i < b; i++) {
        res *= a;
    }
    return res;
}

class Keta {

    vector<int> digits;

public:
    Keta(ll i) : digits(log10(i) + 1) {
        for (int k = 0; k < digits.size(); k++) {
            digits[k] = i % 10;
            i /= 10;
        }
    }

    int keta() {
        return digits.size();
    }

    int get(int index) {
        assert(index != 0);
        assert(index <= keta());
        return digits[index - 1];
    }

    int sum(int start, int end) {
//        assert(start <= end);
        int ans = 0;
        for (int i = start; i <= end; i++) {
            ans += get(i) * pow2(10, i - 1);
        }
        return ans;
    }

};


ll solve(ll s) {
    Keta keta(s);
    ll ans = 0;
    for (int d = keta.keta(); d >= 1; d--) {
        ll rate = pow2(10, d - 2) * (d - 1);
        for (int i = 1; i <= keta.get(d); i++) {
            ans += rate;
            if (i == 2) {
                ll spe = pow2(10, d - 1);
                ans += spe;
            }
        }
        if (keta.get(d) == 1) {
            ll plus = keta.sum(1, d - 1) + 1;
            ans += plus;
        }
    }
    return ans;
}

int main() {
    ll i;
    cin >> i;
    ll ans = solve(i);
    cout << ans << endl;
}