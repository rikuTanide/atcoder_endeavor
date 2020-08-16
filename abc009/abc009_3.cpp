#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<int> &o) {
    int a;
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
    int n, k;
    string s;

    cin >> n >> k >> s;
    string determine;

    auto check = [&](char c) -> bool {
        int cc = 0;
        for (char t : s) if (t == c) cc++;
        for (char t : determine) if (t == c) cc--;
        if (cc <= 0) return false;

        int j = k;

        string next = determine + c;
        rep(i, next.size()) {
            if (s[i] != next[i]) j--;
        }

        {
            // coder
            // toder

            vector<int> org_counts(26);
            for (char t : s) org_counts[t - 'a']++;
            for (char t : next) org_counts[t - 'a']--;

//            vector<int> mod_counts(26);
//            for (char t : s) mod_counts[t - 'a']++;
            rep(i, n) if (i >= next.size()) org_counts[s[i] - 'a']--;

            rep(i, 26) j -= max(org_counts[i], 0);

            return j >= 0;

        }
    };

    rep(i, n) {
        for (char c = 'a'; c <= 'z'; c++) {
            if (check(c)) {
                determine += c;
                break;
            }
        }
    }

    cout << determine << endl;

}
