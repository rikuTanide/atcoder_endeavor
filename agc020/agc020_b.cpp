#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
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
    int n;
    cin >> n;
    vector<ll> call(n);
    rep(i, n) cin >> call[i];

    if (call.back() != 2) {
        cout << -1 << endl;
        ret();
    }

    vector<ll> cs = call;
    reverse(cs.begin(), cs.end());
    vector<ll> ds = cs;
    for (int i = 1; i < n; i++) {
        ll prev = ds[i - 1];
        ll next = cs[i];
        ll rate = (next + prev - 1) / next;
        ds[i] = next * rate;
    }

    vector<ll> es = cs;
    es[0] = 3;
    for (int i = 1; i < n; i++) {
        ll prev = es[i - 1];
        ll next = cs[i];
        prev++;
        ll rate = (next + prev - 1) / next;
        es[i] = next * rate - 1;
    }

    rep(i, n) {
        if (es[i] < ds[i]) {
            cout << -1 << endl;
            ret();
        }
    }

    cout << ds.back() << ' ' << es.back() << endl;

}

