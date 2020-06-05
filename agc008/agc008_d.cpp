#include <bits/stdc++.h>

const double PI = 3.14159265358979323846;
using namespace std;
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

std::istream &operator>>(std::istream &in, set<int> &o) {
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
typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;

struct E {
    int i, place, count;

    E(int i, int place, int count) : i(i), place(place), count(count) {};
};


int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    rep(i, n) cin >> v[i];
    for (int &i : v) i--;

    vector<int> tmp(n * n, -1);
    rep(i, n) tmp[v[i]] = i + 1;


    auto st = [](E &e1, E &e2) {
        return e1.place < e2.place;
    };
    auto gt = [&](E &e1, E &e2) {
        return e1.place > e2.place;
    };

    priority_queue<E, vector<E>, decltype(gt)> l(gt);
    rep(i, n) if (i > 0) l.emplace(i, v[i], i);

    priority_queue<E, vector<E>, decltype(st)> r(st);
    rep(i, n - 1) r.emplace(i, v[i], n - 1 - i);


    rep(i, n * n) {
        if (tmp[i] != -1) continue;
        if (l.empty()) continue;

        E t = l.top();
        l.pop();
        tmp[i] = t.i + 1;
        int count = t.count - 1;
        if (count == 0) continue;
        l.emplace(t.i, t.place, count);
    }


    for (int i = n * n - 1; i >= 0; i--) {
        if (tmp[i] != -1) continue;
        if (r.empty()) continue;

        E t = r.top();
        r.pop();
        tmp[i] = t.i + 1;
        int count = t.count - 1;
        if (count == 0) continue;
        r.emplace(t.i, t.place, count);
    }

    cout << "Yes" << endl;
    rep(i, n * n) cout << tmp[i] << endl;

}
