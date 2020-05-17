#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<double, double> P;
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

    ll n, k;
    cin >> n >> k;

    vector<ll> numbers(n);
    rep(i, n) cin >> numbers[i];

    vector<ll> f(200000 + 1, -1), l(200000 + 1, -1);
    vector<ll> ne(n);

    rep(i, n) {
        ne[i] = i;
        if (f[numbers[i]] == -1) {
            f[numbers[i]] = l[numbers[i]] = i;
        } else {
            ne[l[numbers[i]]] = i;
            l[numbers[i]] = i;
        }
    }

    rep(i, 200000 + 1) if (l[i] > -1) ne[l[i]] = f[i];
    int index = 0, cnt = 1;
    while (true) {
        int next = ne[index];
        if (next <= index) cnt++;
        index = (next + 1) % n;
        if (index == 0) break;
    }

    k %= cnt;

    vector<ll> v;
    set<ll> used;
    rep(i, k) {
        for (ll l: numbers) {
            if (used.find(l) == used.end()) {
                v.push_back(l);
                used.insert(l);
            } else {
                while (v.back() != l) {
                    ll b = v.back();
                    used.erase(b);
                    v.pop_back();
                }
                assert(v.back() == l);
                used.erase(l);
                v.pop_back();

            }
        }
    }
    for (ll l : v) cout << l << ' ';
    cout << endl;
    
}