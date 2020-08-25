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

struct Food {
    int t, a;
};

int main() {
    int n, x;
    cin >> n >> x;

    vector<Food> foods(n);
    for (Food &food: foods) cin >> food.t;
    for (Food &food: foods) cin >> food.a;

    map<int, vector<Food> > m;
    for (Food f : foods) m[f.t].push_back(f);

    auto check = [&](int mid) -> bool {
        auto comp = [](Food f1, Food f2) {
            return f1.a < f2.a;
        };
        priority_queue<Food, vector<Food>, decltype(comp)> q(comp);

        for (Food f : foods) if (f.t > mid) q.push(f);

        ll sum = 0;
        for (int i = mid; i > 0; i--) {
            for (Food f : m[i]) q.push(f);
            if (q.empty())continue;
            sum += q.top().a;
            q.pop();
        }

        return sum >= x;
    };


    int floor = 0, ceil = 1e6;
    if (!check(ceil)) {
        cout << -1 << endl;
        ret();
    }

    while (floor + 1 < ceil) {
        int mid = (floor + ceil) / 2;
        bool ok = check(mid);
        if (ok) ceil = mid;
        else floor = mid;
    }

    cout << ceil << endl;


}
