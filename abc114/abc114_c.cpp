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
typedef priority_queue<string, vector<string>, greater<string> > PQ_ASK;

ll has(ll f, ll c) {
    while (f > 0) {
        ll h = f % 10;
        if (h == c) return true;
        f /= 10;
    }
    return false;
}

bool check(ll f) {
    vector<ll> c = {3, 5, 7};

    for (ll ci : c) {
        bool b = has(f, ci);
        if (b) continue;
        else return false;
    }
    return true;
}

int main() {

    ll n;
    cin >> n;

    queue<ll> q;
    q.push(0);

    int ans = 0;
    while (!q.empty()) {
        ll f = q.front();
        q.pop();
        if (f > n) continue;
        bool b = check(f);
        if (b) {
            ans++;
        }
        for (ll c : {3, 5, 7}) {
            q.push(f * 10 + c);
        }

    }
    cout << ans << endl;

}