#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<ll, ll> P;
const ll INF = 1e15;
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


int main() {
    int n;
    ll a, b;
    cin >> n >> a >> b;

    vector<ll> monsters(n);
    rep(i, n) cin >> monsters[i];

    auto check = [&](ll mid) {
        vector<ll> m = monsters;
        rep(i, n) m[i] = max(m[i] - (mid * b), 0ll);

        ll count = 0;
        ll na = a - b;
        for (ll h : m) count += (h + na - 1) / na;
        return count <= mid;
    };

    ll floor = 0, ceil = INF;
    while (floor + 1 < ceil) {
        ll mid = (floor + ceil) / 2;
        bool ok = check(mid);
        if (ok) {
            ceil = mid;
        } else {
            floor = mid;
        }
    }
    assert(check(floor) == false);
    assert(check(ceil) == true);

    cout << ceil << endl;
}

