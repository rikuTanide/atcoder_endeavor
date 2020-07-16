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
    string s, t;
    cin >> s >> t;
    string ss = s + s;

    vector<vector<int>> table(26);
    rep(i, ss.size()) {
        char c = ss[i];
        int j = c - 'a';
        table[j].push_back(i);
    }

    for (char c : t) {
        if (table[c - 'a'].empty()) {
            cout << -1 << endl;
            ret();
        }
    }

    ll prev = 0;
    for (char c : t) {
        int ci = c - 'a';
        int next = *lower_bound(table[ci].begin(), table[ci].end(), prev % s.size());
        ll add = next - (prev % s.size()) + 1;
        prev += add;
    }
    cout << prev << endl;

}