#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
//typedef long long ll;
typedef long long ll;
//typedef pair<int, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = 10e15;
const ll MINF = -10e10;
//const int INF = INT_MAX / 100;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("~/Downloads/02.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;
const int mod = 1000000007;
const double PI = 3.14159265358979323846;

typedef pair<ll, ll> P;

struct Machine {
    ll begin, end;
};

class Conv {
    ll cursor = 0;
    map<ll, ll> to_short; // <original, small >
    map<ll, ll> to_long; // <small, original>

    std::set<ll> _prepare;

public:
    void set(ll original) {
        if (to_short.find(original) != to_short.end()) {
            return;
        }
        to_long[cursor] = original;
        to_short[original] = cursor;
        cursor++;
    }

    ll revert(ll after) {
        assert(to_long.find(after) != to_long.end());
        return to_long[after];
    }

    ll convert(ll original) {
        assert(to_short.find(original) != to_short.end());
        return to_short[original];
    }

    ll next() {
        return cursor;
    }

    void prepare(ll l) {
        _prepare.insert(l);
    }

    void build() {
        for (ll a : _prepare) {
            set(a);
        }
    }

};


int main() {
    int n;
    cin >> n;


    vector<Machine> machines;
    rep(i, n) {
        Machine m;
        ll x, l;
        cin >> x >> l;

        m.begin = x - l + 1;
        m.end = x + l - 1;
        machines.push_back(m);

    }

//    Conv conv;
//    for (Machine &m : machines) {
//        conv.prepare(m.begin);
//        conv.prepare(m.end);
//    }
//    conv.build();
//
//
//    rep(i, n) {
//        machines[i].begin = conv.convert(machines[i].begin);
//        machines[i].end = conv.convert(machines[i].end);
//    }

    sort(machines.begin(), machines.end(), [](Machine &m, Machine &n) {
        if (m.end != n.end) return m.end < n.end;
        return m.begin > n.end;
    });

    ll start = LONG_LONG_MIN;
    int count = 0;
    for (Machine &m: machines) {
        if (m.begin > start) {
            count++;
            start = m.end;
        }
    }

    cout << count << endl;

}

