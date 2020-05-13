#include <bits/stdc++.h>

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

struct Query {
    ll a, b, c, d;
};

std::istream &operator>>(std::istream &in, Query &o) {
    cin >> o.a >> o.b >> o.c >> o.d;
    o.a--;
    o.b--;
    return in;
}


const int mod = 998244353;

class CumulativeSum {
    vector<ll> numbers;
    vector<ll> sums;

public:
    CumulativeSum(int n) {
        numbers.resize(n);
        sums.resize(n);
    }

    void set(int i, ll value) {
        numbers[i] = value;
    }

    ll getSum(int i) {
        if (i == -1) return 0;
        if (i == sums.size()) return sums.back();
        return sums[i];
    }

    ll getSectionSum(int start, int end) {
        return getSum(end) - getSum(start - 1);
    }

    void calculate() {
        for (int i = 0; i < numbers.size(); i++) {
            sums[i] = getSum(i - 1) + numbers[i];
        }
    }

};


int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    rep(i, n) cin >> v[i];

    CumulativeSum cs(n);
    rep(i, n) cs.set(i, v[i]);
    cs.calculate();

    vector<P> split_c;

    // 仕切りは左に属する
    rep(i, n) {
        if (i < 1) continue;
        if (n - i <= 2) continue;
        split_c.emplace_back(i, i + 1);
    }

    auto split_b = [&](int start, int end) {
        assert(start < end);
        int floor = start, ceil = end;
        while (floor + 1 < ceil) {
            int mid = (floor + ceil) / 2;
            assert(mid + 1 <= end);
            ll a = cs.getSectionSum(start, mid);
            ll b = cs.getSectionSum(mid + 1, end);
            if (a > b) ceil = mid;
            else floor = mid;
        }
        return P(floor, floor + 1);
    };

    ll ans = INF;

    for (P p :split_c) {
        P l = split_b(0, p.first);
        P r = split_b(p.second, n - 1);

        ll
                a = cs.getSectionSum(0, l.first),
                b = cs.getSectionSum(l.second, p.first),
                c = cs.getSectionSum(p.second, r.first),
                d = cs.getSectionSum(r.second, n - 1);

        vector<ll> u = {a, b, c, d};
        sort(u.begin(), u.end());
        ll now = u.back() - u.front();
        cmin(ans, now);
    }

    cout << ans << endl;
}
