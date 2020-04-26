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

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

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

vector<vector<int>> get_array(string &s, int k) {
    vector<int> tmp(26);
    rep(i, k) {
        tmp[s[i] - 'a']++;
    }
    vector<vector<int>> res;
    res.push_back(tmp);
    rep(i, s.size() - k) {
        tmp[s[i] - 'a']--;
        tmp[s[i + k] - 'a']++;
        res.push_back(tmp);
    }
    return res;
}

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    auto res = get_array(s, k);
    multiset<vector<int>> sres;
    for(auto r : res) sres.insert(r);

    auto del = [&](int i) {
        if (i >= res.size()) return;
        auto &r = res[i];
//        cout << "del ";
//        for(int j : r) cout << j << ' ';
//        cout << endl;
        auto it = sres.lower_bound(r);
        assert(it != sres.end());
        sres.erase(it);
    };

//    cout << "res" << endl;
//    for (auto r :res) {
//        rep(i, 26) cout << r[i] << ' ';
//        cout << endl;
//    }

//    cout << "sres" << endl;

//    for (auto r :sres) {
//        rep(i, 26) cout << r[i] << ' ';
//        cout << endl;
//    }

    rep(i, k) del(i);

    rep(i, res.size()) {
        auto &r = res[i];
//        cout << "check ";
//        for(int j : r) cout << j << ' ';
//        cout << endl;

        auto it = lower_bound(sres.begin(), sres.end(), r);
        if (it == sres.end()) {
            del(i + k);
        } else {
            cout << "YES" << endl;
            ret();
//            del(i + k);

        }
    }
//
//    for (auto r :sres) {
//        rep(i, 26) cout << r[i] << ' ';
//        cout << endl;
//    }
    cout << "NO" << endl;
}

