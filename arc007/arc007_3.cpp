#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
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
    string s;
    cin >> s;

    vector<string> v;
    rep(i, s.size()) {
        char back = s.back();
        s.pop_back();
        s = back + s;
        v.push_back(s);
    }

    vector<int> candidates;

    for (int i = 0; i < (1 << v.size()); i++) {
        vector<bool> bs(s.size(), false);
        for (int j = 0; j < v.size(); j++) {
            if ((i >> j) & 1) {
                string t = v[j];
                rep(k, t.size()) {
                    if (t[k] == 'o') {
                        bs[k] = true;
                    }
                }
            }
        }

        bool ok = true;
        for (bool b : bs) if (!b) ok = false;

        if (ok) candidates.push_back(__builtin_popcount(i));
    }

    cout << *min_element(candidates.begin(), candidates.end()) << endl;

}
