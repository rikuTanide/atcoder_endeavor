#include <bits/stdc++.h>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

std::istream &operator>>(std::istream &in, set<ll> &o) {
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

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//const ll mod = 1e10;
//typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;


class Set {
    multiset<ll> s;

public:
    void insert(ll l) {
        s.insert(-l);
    }

    ll find(ll l) {
        auto it = s.upper_bound(-l);
        if (it == s.end()) return -1;
        return -(*it);
    }

    void erase(ll l) {
        s.erase(s.find(-l));
    }

};

int main() {
    Set s;

    int n;
    cin >> n;
    rep(i, 1 << n) {
        ll a;
        cin >> a;
        s.insert(a);
    }

    ll top = s.find(INF);
    multiset<ll, greater<ll>> used;
    used.insert(top);

    s.erase(top);

    rep(i, n) {
        vector<ll> next;
        for (ll u : used) {
            ll t = s.find(u);
            if (t == -1) {
                cout << "No" << endl;
                ret();
            }
            s.erase(t);
            next.push_back(t);
        }
        for (ll l : next) used.insert(l);
    }

    cout << "Yes" << endl;
}