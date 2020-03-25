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
const int mod = 1000000007;
//const ll mod = 1e10;
typedef priority_queue<string, vector<string>, greater<string> > PQ_ASK;

#include <iostream>
#include <vector>

using namespace std;

class CumulativeSum {
    vector<ll> numbers;
    vector<ll> sums;

public:
    CumulativeSum(int n) {
        numbers.resize(n);
        sums.resize(n);
    }

    void set(int i, ll value) {
        numbers[i] = value;
    }

    ll getSum(int i) {
        if (i == -1) return 0;
        if (i == sums.size()) return 0;
        return sums[i];
    }

    ll getSectionSum(int start, int end) {
        return getSum(end) - getSum(start - 1);
    }

    void calculate() {
        for (int i = 0; i < numbers.size(); i++) {
            sums[i] = getSum(i - 1) + numbers[i];
        }
    }

};


int main() {
    ll n, m;
    cin >> n >> m;

    vector<ll> candies(n);
    rep(i, n) cin >> candies[i];

    CumulativeSum cs(n);
    rep(i, n) cs.set(i, candies[i]);
    cs.calculate();

    map<ll, ll> happened;
    rep(i, n) happened[cs.getSum(i) % m]++;

    ll ans = 0;
    ans += happened[0];
    rep(i, n) {
        happened[cs.getSum(i) % m]--;
        ll prev = cs.getSum(i) % m;// (m - ) % m;
        ans += happened[prev];
    }

    cout << ans << endl;

    for (auto e : happened) assert(e.second == 0);

}



