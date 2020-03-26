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
    ll n;
    cin >> n;
    vector<ll> numbers(n);
    rep(i, n) cin >> numbers[i];
    sort(numbers.rbegin(), numbers.rend());

    map<ll, ll> counts;
    for (ll l : numbers) counts[l]++;
    ll ans = 0;
    rep(i, n) {
        ll l = numbers[i];
        assert(counts[l] >= 0);
        if (counts[l] == 0) continue;
        counts[l]--;

        ll max_bit = -1;
        for (int j = 0; j < 64; j++) {
            bool b = ((l >> j) & 1);
            if (b) max_bit = j;
        }
        assert(max_bit >= 0);
        ll target = 1ll << (max_bit + 1);
        target -= l;
        assert(target >= 0);
        if (counts.find(target) != counts.end() && counts[target] > 0) {
            ans++;
            counts[target]--;
        }
    }
    cout << ans << endl;
}
