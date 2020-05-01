#include <bits/stdc++.h>


using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
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

typedef pair<ll, ll> P;

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

struct Food {
    ll time, happy;
};

bool check(int mid, int n, vector<Food> &foods, ll x) {
    map<int, vector<ll>> m;
    priority_queue<ll> q;
    for (Food food : foods) {
        if (food.time > mid) q.push(food.happy);
        else m[food.time].push_back(food.happy);
    }

    ll sum = 0;
    for (int t = mid; t > 0; t--) {
        for (ll d : m[t]) q.push(d);
        if (q.empty()) continue;
        sum += q.top();
        q.pop();
    }
    return sum >= x;
}

int main() {
    int n;
    ll x;
    cin >> n >> x;

    vector<Food> foods(n);
    rep(i, n) cin >> foods[i].time;
    rep(i, n) cin >> foods[i].happy;


    int floor = 0, ceil = 10e5 + 100;

    if (!check(ceil, n, foods, x)) {
        cout << -1 << endl;
        ret();
    }

    while (floor + 1 < ceil) {
        int mid = (floor + ceil) / 2;
        bool b = check(mid, n, foods, x);
        if (b) ceil = mid;
        else floor = mid;
    }

    cout << ceil << endl;
}
