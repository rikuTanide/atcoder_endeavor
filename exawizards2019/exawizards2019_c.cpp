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

struct Query {
    char c, d;
};

std::istream &operator>>(std::istream &in, Query &o) {
    cin >> o.c >> o.d;
    return in;
}

// 落ちるヤツの数
int check(int n, string &s, vector<Query> &queries) {
    int floor = 0;
    int ceil = n - 1;

    function<bool(int)> ch = [&](int i) {
        int now = i;
        for (Query &q : queries) {
            if (q.c != s[now]) continue;
            else if (q.d == 'L') now--;
            else if (q.d == 'R') now++;
            if (now == -1) return false;
        }
        return true;
    };

    if (ch(floor)) {
        return 0;
    }
    if (!ch(ceil)) {
        return n;
    }

    while (floor + 1 < ceil) {
        int mid = (floor + ceil) / 2;
        bool b = ch(mid);
        if (b) ceil = mid;
        else floor = mid;
    }

    return floor + 1;

}

int main() {
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<Query> queries(q);
    rep(i, q) cin >> queries[i];

    int l = check(n, s, queries);
    reverse(s.begin(), s.end());
    rep(i, q) queries[i].d = queries[i].d == 'L' ? 'R' : 'L';
    int r = check(n, s, queries);

    int ans = max(n - l - r, 0);


    cout << ans << endl;

}