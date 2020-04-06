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
const int mod = 1000000007;
//const ll mod = 1e10;
typedef priority_queue<string, vector<string>, greater<string> > PQ_ASK;

#include <iostream>
#include <vector>

using namespace std;

ll check(int n, ll mid, ll k, vector<ll> &skills, vector<ll> &foods) {
    ll sum = 0;
    rep(i, n) {
        ll ns = mid / foods[i];
        if (ns < skills[i]) {
            sum += (skills[i] - ns);
        }
    }
    return k >= sum;
}

int main() {
    int n;
    ll k;
    cin >> n >> k;

    vector<ll> skills(n), foods(n);
    rep(i, n) cin >> skills[i];
    rep(i, n) cin >> foods[i];

    sort(skills.begin(), skills.end());
    sort(foods.rbegin(), foods.rend());

    bool b = check(n, 0, k, skills, foods);
    if (b) {
        cout << 0 << endl;
        ret();
    }

    ll floor = 0, ceil = INF;

    while (floor + 1 < ceil) {
        ll mid = (floor + ceil) / 2;
        bool b = check(n, mid, k, skills, foods);
        if (b) {
            ceil = mid;
        } else {
            floor = mid;
        }
    }
    cout << ceil << endl;
}