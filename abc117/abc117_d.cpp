#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
using namespace std;
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

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//const ll mod = 1e10;
typedef priority_queue<string, vector<string>, greater<string> > PQ_ASK;

#include <iostream>
#include <vector>

using namespace std;

const int mod = 1000000007;


int main() {
    int n;
    ll k;
    cin >> n >> k;

    vector<ll> numbers(n);
    rep(i, n) cin >> numbers[i];

    vector<ll> zero_counts(64), one_counts(64);
    for (ll l : numbers) {
        rep(i, 64) {
            bool b = (l >> i) & 1;
            if (b) one_counts[i]++;
            else zero_counts[i]++;
        }
    }

    vector<ll> contribution(64, 0);
    rep(i, 64) {
        ll rate = 1ll << i;
        ll c = zero_counts[i] * rate - one_counts[i] * rate;
        contribution[i] = c;
    }

    vector<bool> k_bits(64);

    rep(i, 64) {
        bool b = (k >> i) & 1;
        k_bits[i] = b;
    }

    vector<ll> candidate;

    auto check = [&](vector<bool> &k_bits) {
        ll x = 0;
        rep(i, 64) {
            if (!k_bits[i]) continue;
            if (contribution[i] <= 0) continue;
            ll j = (1ll << i);
            x += j;
        }

        ll ans = 0;
        for (ll l : numbers) ans += (l ^ x);

        candidate.push_back(ans);
    };


    check(k_bits);

    rep(i, 64) {
        if (!k_bits[i]) continue;
        vector<bool> k_bits2 = k_bits;
        k_bits2[i] = false;
        rep(j, i) k_bits2[j] = true;
        check(k_bits2);
    }

    cout << *max_element(candidate.begin(), candidate.end()) << endl;

}
