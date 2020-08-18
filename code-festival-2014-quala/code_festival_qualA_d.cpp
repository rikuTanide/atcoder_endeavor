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
    ll a;
    int k;
    cin >> a >> k;

    string s = to_string(a);
    int n = s.size();
    ll ans = INF;
    for (int i = 0; i <= n; i++) {
        set<char> used;
        rep(j, i) used.insert(s[j]);
        if (used.size() > k) continue;
        char f = s[i];

        for (char u = '0'; u <= '9'; u++) {
            set<char> used_next = used;

            if (i == 0 && u == '0') {
                used_next.insert('9');
            } else {
                used_next.insert(u);
            }

            if (i != 0 && used_next.size() > k) continue;

            string t;
            t.resize(n);
            rep(j, i) t[j] = s[j];
            t[i] = u;
            char ume = [&]() -> char {
                if (f > u) {
                    // 小さくなったから一番大きいヤツ
                    auto it = used_next.end();
                    it--;
                    return *it;
                } else {
                    return *used_next.begin();
                }
            }();

            for (int j = i + 1; j < n; j++) {
                t[j] = ume;
            }

            ll next = atoll(t.c_str());
            cmin(ans, abs(next - a));
        }
    }
    cout << ans << endl;

}
