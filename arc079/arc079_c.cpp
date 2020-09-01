#include <bits/stdc++.h>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

std::istream &operator>>(std::istream &in, set<ll> &o) {
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
//typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;

ll simulate(int n, vector<ll> v) {
    int ans = 0;
    while (*max_element(v.begin(), v.end()) >= n) {
        ans++;
        rep(i, n) v[i]++;
        *max_element(v.begin(), v.end()) -= (n + 1);
    }
    return ans;
}

class Q {
    priority_queue<ll> q;
    ll up_count = 0;
public:
    void push(ll l) {
        q.push(l - up_count);
    }

    void pop() {
        q.pop();
    }

    ll top() {
        return q.top() + up_count;
    }

    void up(ll k) {
        up_count += k;
    }
};


int main() {
    int n;
    cin >> n;
    vector<ll> v(n);
    rep(i, n) cin >> v[i];
    Q q;
    rep(i, n) q.push(v[i]);

    ll ans = 0;
    while (q.top() >= n) {
        ll top = q.top();
        ll c = top / n;
        ans += c;
        q.pop();
        top -= n * c;
        q.up(c);
        q.push(top);
    }
    cout << ans << endl;
}