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



int main() {
    int n, k;
    cin >> n >> k;
    vector<int> prev(n);
    rep(i, n) cin >> prev[i];

    rep(_, k) {
        vector<int> next(n, 0);
        rep(j, n) {
            int d = prev[j];
            int l = max(j - d, 0);
            next[l]++;
            int r = j + d + 1;
            if (r < n) next[r]--;
        }
        rep(i, n - 1) next[i + 1] += next[i];

        if (next == prev) break;
        prev = next;
    }

    for (ll l : prev) cout << l << ' ';

}