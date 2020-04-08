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
    vector<ll> numbers2;

    auto is_uu = [&](int i) {
        return numbers2[i - 1] < numbers2[i] && numbers2[i] < numbers2[i + 1];
    };

    auto is_dd = [&](int i) {
        return numbers2[i - 1] > numbers2[i] && numbers2[i] > numbers2[i + 1];
    };

    for (ll l : numbers)
        if (numbers2.empty()) numbers2.push_back(l);
        else if (numbers2.back() != l) numbers2.push_back(l);

    int ans = numbers2.size();
    rep(i, numbers2.size()) {
        if (i == 0) continue;
        else if (i == numbers2.size() - 1) continue;
        else if (is_uu(i) || is_dd(i)) ans--;
        else continue;
    }
    if (ans <= 2) ans = 0;
    cout << ans << endl;
}
