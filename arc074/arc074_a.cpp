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


vector<P> split(ll w, ll h) {
    vector<P> ans;
    if (w > 1) {
        ll wa = w / 2;
        ans.push_back(P(wa * h, (w - wa) * h));
    }
    if (h > 1) {
        ll ha = h / 2;
        ans.push_back(P(ha * w, (h - ha) * w));
    }

    for (P p : ans) assert(p.second > 0 && p.first > 0);
    return ans;

}

int main() {
    ll h, w;
    cin >> h >> w;


    ll ans = INF;

    for (ll i = 1; i < h; i++) {
        ll bar1 = w * i;
        for (P bar23 : split(w, h - i)) {
            vector<ll> choco = {bar1, bar23.first, bar23.second};
            sort(choco.begin(), choco.end());
            ll now = choco.back() - choco.front();
            cmin(ans, now);
        }
    }
    for (ll i = 1; i < w; i++) {
        ll bar1 = h * i;
        for (P bar23 : split(h, w - i)) {
            vector<ll> choco = {bar1, bar23.first, bar23.second};
            sort(choco.begin(), choco.end());
            ll now = choco.back() - choco.front();
            cmin(ans, now);
        }
    }
    cout << ans << endl;

}
