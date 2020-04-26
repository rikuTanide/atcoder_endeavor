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

string get_tb(string &s, string &tmp) {
    string t = s;
    for (char c : tmp) {
        int it = t.find(c);
        assert(it > -1);
        t.erase(t.begin() + it);
    }
    return t;
}

int get_prefix_unmatch(string &sa, string &sb) {
    assert(sa.size() == sb.size());
    int a = 0;
    rep(i, sa.size()) if (sa[i] != sb[i]) a++;
    return a;
}

int get_suffix_min_unmatch(string &sa, string &sb) {
    vector<int> ca(26);
    vector<int> cb(26);
    for (char c : sa) ca[c - 'a']++;
    for (char c : sb) cb[c - 'a']++;
    int ans = 0;
    rep(i, 26) ans += min(ca[i], cb[i]);
    return sa.size() - ans;
}

bool check(string &s, string &tmp, int k) {
    string sa = s.substr(0, tmp.size());
    string sb = s.substr(tmp.size());
    string ta = tmp;
    string tb = get_tb(s, tmp);

    int a = get_prefix_unmatch(sa, ta);
    int b = get_suffix_min_unmatch(sb, tb);

    return k >= a + b;

}

int main() {
    string s;
    int n, k;
    cin >> n >> k >> s;
    multiset<char> t;
    for (char c : s) t.insert(c);

    auto del = [&](char c) {
        auto it = t.find(c);
        t.erase(it);
    };

    string tmp = "";
    rep(i, n) {
        for (char c : t) {
            string next = tmp + c;
            bool b = check(s, next, k);
            if (b) {
                del(c);
                tmp = next;
                break;
            } else {
                continue;
            }
        }
    }
    cout << tmp << endl;
}

