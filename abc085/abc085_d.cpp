#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
//using namespace boost::multiprecision;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
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
typedef priority_queue<long long, vector<long long>, greater<long long> > PQ_ASK;


int main() {

    int n, h;
    cin >> n >> h;

    vector<int> knife_throw(n), knife_saw(n);
    rep(i, n) cin >> knife_saw[i] >> knife_throw[i];

    ll m = *max_element(knife_saw.begin(), knife_saw.end());

    vector<int> need_knife_throw;
    for (ll a :knife_throw) if (a > m) need_knife_throw.push_back(a);
    sort(need_knife_throw.rbegin(), need_knife_throw.rend());

    ll ans = 0;
    ll hit = 0;
    for (int i = 0; i < need_knife_throw.size(); i++) {
        ans++;
        hit += need_knife_throw[i];
        if (hit >= h) {
            cout << ans << endl;
            ret();
        }
    }

    ll nokori = h - hit;

    ans += ((nokori + m - 1) / m);
    cout << ans << endl;


}
