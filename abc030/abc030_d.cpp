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
    ll n, a;
    string k;
    cin >> n >> a >> k;
    a--;
    vector<int> nexts(n);
    rep(i, n) cin >> nexts[i], nexts[i]--;

    ll start_count, cycle_count;

    {
        map<int, int> used;
        int now = a;
        int count = 0;
        while (used.find(now) == used.end()) {
            used[now] = count;
            count++;
            now = nexts[now];
        }

        start_count = used[now];
        cycle_count = count - start_count;

    }


//    cout << start_count << ' ' << cycle_count << endl;

    auto check = [&](int start, int x) -> int {

        int now = start;
        rep(i, x) {
            now = nexts[now];
        }

        return now;

    };

    if (k.size() <= 7) {
        ll kl = atoll(k.c_str());
        cout << check(a, kl) + 1 << endl;
        ret();
    }

    ll l = 0;

    for (char c : k) {
        int i = c - '0';
        l *= 10;
        l += i;
        l %= cycle_count;
    }

    l += (n * cycle_count);
    l -= start_count;
    l %= cycle_count;

    cout << check(start_count, l) + 1 << endl;
}
