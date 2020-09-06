#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
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

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

void print(vector<ll> &v) {
    for (ll l : v) cout << l << ' ';
    cout << endl;
}

const int ma = 1e6;

int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> v(n);
    rep(i, n) cin >> v[i];

    vector<vector<int>> index(ma);
    rep(i, n) index[v[i]].push_back(i);
    rep(i, n) index[v[i]].push_back(i + n);
    int loop = 0;

    {
        int now = 0;
        do {
            int now_i = v[now];
            auto it = upper_bound(index[now_i].begin(), index[now_i].end(), now);
            int next = (*it) + 1;
            if (next >= n) loop++;
            now = next % n;
        } while (now != 0);
    }

    k %= loop;

    vector<ll> tmp;
    rep(a, k) {
        rep(b, n) {
            ll l = v[b];
            if (find(tmp.begin(), tmp.end(), l) == tmp.end()) {
                tmp.push_back(l);
            } else {
                while (find(tmp.begin(), tmp.end(), l) != tmp.end()) {
                    tmp.pop_back();
                }
            }
        }
    }
    print(tmp);

}
