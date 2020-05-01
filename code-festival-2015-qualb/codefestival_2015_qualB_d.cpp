#include <bits/stdc++.h>


using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<string> &o) {
    string a;
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

typedef pair<ll, ll> P;

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;


int main() {
    int n;
    cin >> n;

    set<P> ranges;
    ranges.insert({-1, -2});
    ranges.insert({2 * INF, INF});

    rep(i, n) {
        ll s, c;
        cin >> s >> c;

        ll os = s;

        {
            auto it = ranges.lower_bound(P(s, 0));
            if (s >= it->second) {
                c += it->first - it->second + 1;
                s = it->second;
                os = it->second;
                ranges.erase(it);
            }
        }

        while (c) {
            auto it = ranges.lower_bound(P(s, 0));
            if (s + c - 1 == it->second - 1) {
                cout << s + c - 1 << endl;
                P p(it->first, os);
                ranges.erase(it);
                ranges.insert(p);
                break;
            } else if (s + c - 1 < it->second - 1) {
                cout << s + c - 1 << endl;
                ranges.insert(P(s + c - 1, os));
                break;
            } else {
                c -= it->second - s;
                s = it->first + 1;
                ranges.erase(it);
            }
        }

    }

}