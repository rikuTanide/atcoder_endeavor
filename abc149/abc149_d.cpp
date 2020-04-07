#include <bits/stdc++.h>

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

int main() {
    int n, k, gu, choki, par;
    cin >> n >> k >> gu >> choki >> par;

    string t;
    cin >> t;
    vector<bool> is_win(t.size(), false);

    auto was_win = [&](int i, char c) {
        if (i < 0) return false;
        if (t[i] != c) return false;
        bool b = is_win[i];
        return b;
    };

    rep(i, n) {
        if (was_win(i - k, t[i])) {
            is_win[i] = false;
        } else {
            is_win[i] = true;
        }
    }


    ll ans = 0;
    rep(i, n) {
        if (!is_win[i]) continue;
        if (t[i] == 'r') {
            ans += par;
        } else if (t[i] == 's') {
            ans += gu;
        } else {
            ans += choki;
        }
    }
    cout << ans << endl;


}