#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
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


int main() {
    int n;
    cin >> n;
    vector<ll> numbers(n);
    rep(i, n) cin >> numbers[i];

    auto is_uu = [&](int i) {
        return numbers[i - 1] < numbers[i] && numbers[i] < numbers[i + 1];
    };

    auto is_dd = [&](int i) {
        return numbers[i - 1] > numbers[i] && numbers[i] > numbers[i + 1];
    };

    auto is_ee = [&](int i) {
        return numbers[i - 1] == numbers[i];
    };

    int ans = n;
    rep(i, n) {
        if (i == 0) continue;
        else if (i == n - 1 && !is_ee(i)) continue;
        else if (is_ee(i)) ans--;
        else if (is_uu(i) || is_dd(i)) ans--;
        else continue;
    }
    if (ans <= 2) ans = 0;
    cout << ans << endl;
}
