#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<ll, ll> P;
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

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

struct Mountain {
    ll height;
    int index;
};

int main() {
    int n;
    cin >> n;

    vector<Mountain> mountains(n);
    rep(i, n) cin >> mountains[i].height;
    rep(i, n) mountains[i].index = i;

    sort(mountains.rbegin(), mountains.rend(), [](Mountain &m1, Mountain &m2) { return m1.height < m2.height; });
    vector<vector<ll>> v;
    v.push_back(vector<ll>{mountains[0].index});
    rep(i, n) {
        if (i == 0) continue;
        if (mountains[i - 1].height == mountains[i].height) v.back().push_back(mountains[i].index);
        else v.push_back(vector<ll>{mountains[i].index});
    }

    set<int> used_indexes;
    vector<int> ans(n);
    for (auto &u : v) {
        for (int i : u) {
            if (used_indexes.empty()) ans[i] = n - 1;
            else {
                int end = [&] {
                    auto end_it = used_indexes.upper_bound(i);
                    if (end_it == used_indexes.end()) return n;
                    return *end_it;
                }();
                int start = [&] {
                    auto begin_it = used_indexes.upper_bound(i);
                    if (begin_it == used_indexes.begin()) return -1;
                    begin_it--;
                    return *begin_it;
                }();

                int now = end - start - 2;
                ans[i] = now;
            }
        }
        for (int i : u)used_indexes.insert(i);
    }

    for (int i : ans) cout << i << endl;

}
