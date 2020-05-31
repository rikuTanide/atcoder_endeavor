#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const long double EPS = 1e-9;

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

std::istream &operator>>(std::istream &in, set<char> &o) {
    string a;
    in >> a;
    for (char c : a) o.insert(c);
    return in;
}

std::istream &operator>>(std::istream &in, queue<int> &o) {
    ll a;
    in >> a;
    o.push(a);
    return in;
}

bool contain(set<char> &s, char a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;

const double e = 2.7182818284590452;

int main() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;


    int ans = 0;


    rep(i, 1 << n) {


        bool b = [&]() -> bool {


            string t(n, ' ');
            rep(j, n) {
                if ((i >> j) & 1) t[j] = '1';
                else t[j] = '0';
            };


            rep(j, n) {
                if (s[j] == '0' && t[j] == '1') return false;
                if (s[j] == '1' && t[j] == '0') return false;
            }

            for (int l = 0; l < n; l++) {
                for (int r = l + 1; r <= n; r++) {
                    string u = t.substr(l, r);
                    int x = count(u.begin(), u.end(), '0');
                    int y = count(u.begin(), u.end(), '1');
                    int d = abs(x - y);

                    if (d > k) return false;
                }
            }

            return true;


        }();
        if (b)ans++;

    }
    cout << ans << endl;

}
