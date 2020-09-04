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

struct Counter {
    map<int, int> m;

    ll _values = 0;

    void push(P p) {
        _values += p.second;
        m[p.first]++;
    }

    void pop(P p) {
        _values -= p.second;
        m[p.first]--;
        if (m[p.first] == 0) m.erase(m.find(p.first));
    }

    ll values() {
        ll c = m.size();
        return _values + c * c;
    }

};

int main() {
    int n, k;
    cin >> n >> k;

    vector<P> v(n);
    for (P &p : v) cin >> p.first >> p.second;

    // 種類を全部洗いだす
    // 種類ごとにおいしい順
    //  おいしい順先頭Kこ
    // おいしい順の先頭を除く全部を一個に並べてソート
    // 種類数がKより少なければ、残りからおいしい順に入れる
    // 種類ごとに一番おいしいものを、おいしく無い順にPopして残りをおいしい順にPushする

    set<int> all_types;
    for (P p : v) all_types.insert(p.first);

    map<int, vector<P>> all_sort;
    for (P p : v) all_sort[p.first].push_back(p);
    for (int t : all_types) sort(all_sort[t].begin(), all_sort[t].end());

    vector<P> top_par_types;
    vector<P> rems;


    for (int t : all_types) {
        top_par_types.push_back(all_sort[t].back());
        rep(i, all_sort[t].size() - 1) {
            rems.push_back(all_sort[t][i]);
        }
    }
    sort(top_par_types.rbegin(), top_par_types.rend(), [](P p1, P p2) { return p1.second < p2.second; });
    sort(rems.begin(), rems.end(), [](P p1, P p2) { return p1.second < p2.second; });

    vector<P> first_top_par_types = top_par_types;
    vector<P> first_top_rems;
    vector<P> first_rems = rems;

    Counter counter;
    for (P p :  first_top_par_types)counter.push(p);

    while (first_top_par_types.size() > k) {
        counter.pop(first_top_par_types.back());
        first_top_par_types.pop_back();
    }

    while (first_top_par_types.size() + first_top_rems.size() < k) {
        counter.push(first_rems.back());
        first_top_rems.push_back(first_rems.back());
        first_rems.pop_back();
    }

    ll ans = counter.values();

    while (!first_top_par_types.empty() && !first_rems.empty()) {
        counter.pop(first_top_par_types.back());
        counter.push(first_rems.back());

        first_top_par_types.pop_back();
        first_rems.pop_back();

        ll now = counter.values();
        cmax(ans, now);
    }

    cout << ans << endl;

}
