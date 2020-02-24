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
    int h, w;
    cin >> h >> w;

    vector<int> alphabet(26, 0);
    rep(y, h) rep(x, w) {
            char c;
            cin >> c;
            alphabet[c - 'a']++;
        }

    if (h > w) swap(h, w);

    vector<int> needs;
    for (int i = 0; i < h / 2; i++) {
        for (int j = 0; j < (w / 2); j++) {
            needs.push_back(4);
        }
        if (w % 2 == 1) needs.push_back(2);
    }
    if (h % 2 == 1) {
        for (int j = 0; j < (w / 2); j++) {
            needs.push_back(2);
        }
        if (w % 2 == 1) needs.push_back(1);
    }

    sort(needs.rbegin(), needs.rend());

    priority_queue<ll> q;
    for (ll l : alphabet) if (l != 0) q.push(l);

    for (ll need : needs) {
        if (q.empty()) {
            cout << "No" << endl;
            ret();
        }
        ll t = q.top();
        q.pop();
        if (t < need) {
            cout << "No" << endl;
            ret();
        }
        t -= need;
        assert(t >= 0);
        if (t != 0) q.push(t);
    }
    assert(q.empty());

    cout << "Yes" << endl;

}