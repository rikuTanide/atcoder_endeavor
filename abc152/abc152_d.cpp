#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX / 100;
//const ll INF = 1e15;
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

    int top() {
        return get(keta());
    }
};

ll pow2(ll a, ll b) {
    if (b == 0) return 1;
    ll res = a;
    for (ll i = 1; i < b; i++) {
        res *= a;
    }
    return res;
}

ll calc_bk(ll top, ll back, ll n, ll k) {
    ll start = pow2(10, k + 1) * top + back;
    ll end = start;
    for (ll ik = 0; ik < k; ik++) {
        ll a = 90 * pow2(10, ik);
        end += a;
    }

    if (start > n) return 0;
    if (end < n) {
        return pow2(10, k);
    }

    Keta bk(start);

    ll top_m = top * pow2(10, k + 1);

    ll nm = n - top_m;
    nm /= 10;
    if (n % 10 >= back) nm++;
    return nm;

}

ll calc_b(ll top, ll back, ll n) {
    if (top == 0) return 0;
    ll ans = 0;
    if (top == back) ans++;
    for (ll k = 0; k < 6; k++) {
        // top k k k back;
        ll now = calc_bk(top, back, n, k);
        ans += now;
    }
    return ans;
}

ll count(ll i) {
    ll ans = 0;
//    ll cans = 0;
    for (ll a = 1; a <= i; a++) {
        Keta ak(a);
        ll now = calc_b(ak.get(1), ak.top(), i);
        ans += now;

        for (ll b = 1; b <= i; b++) {

            Keta bk(b);

//            if (ak.get(ak.keta()) == bk.get(1) && ak.get(1) == bk.get(bk.keta())) {
//                cans++;
//            }

        }

    }
    return ans;
}

int main() {

    int n;
    cin >> n;
    if(n <= 9) {
        cout << n << endl;
        return 0;
    }

    ll ans = count(n);

}

