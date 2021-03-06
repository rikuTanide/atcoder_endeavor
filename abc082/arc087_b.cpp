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
    string s;
    int x, y;
    cin >> s >> x >> y;

    int n = s.size();

    vector<int> h = {0}, v = {};
    {
        char o = 'h';
        rep(i, n) {
            if (s[i] == 'T') {
                if (o == 'v') {
                    o = 'h';
                    h.push_back(0);
                } else {
                    o = 'v';
                    v.push_back(0);
                }
            } else {
                if (o == 'v') {
                    v.back()++;
                } else {
                    h.back()++;
                }
            }
        }
    }


    auto check = [](vector<int> seq, int start, int target) -> bool {
        set<int> prev;
        prev.insert(start);
        for (int j : seq) {
            set<int> next;
            for (int i : prev) {
                next.insert(i + j);
                next.insert(i - j);
            }
            prev = next;
        }
        return prev.find(target) != prev.end();
    };

    int first = h[0];
    h.erase(h.begin());
    bool ok_h = check(h, first, x);
    bool ok_v = check(v, 0, y);

    bool ok = ok_h && ok_v;
    cout << (ok ? "Yes" : "No") << endl;

}
