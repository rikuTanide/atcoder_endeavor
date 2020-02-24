#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
//using namespace boost::multiprecision;
using namespace std;
typedef long long ll;
//typedef unsigned long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
//typedef pair<int, int> P;
//typedef pair<ll, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX / 100;
//const ll INF = (1ll << 31) - 1;
const ll INF = 1e15;
//const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
//typedef pair<int, int> P;
//typedef pair<double, double> P;
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
//const int mod = 1000000007;
//const ll mod = 1e10;
typedef priority_queue<long long, vector<long long>, greater<long long> > PQ_ASK;

struct Cake {
    int count, type;

    bool operator<(const Cake &cake) const {
        return (count < cake.count);
    }
};



int main() {
    int k, t;
    cin >> k >> t;

    vector<int> cakes(t);
    rep(i, t)cin >> cakes[i];

    priority_queue<Cake> cake_queue;
    rep(i, t) {
        Cake cake{cakes[i], i};
        cake_queue.push(cake);
    }

    vector<int> order;
    while (!cake_queue.empty()) {
        Cake c = cake_queue.top();
        cake_queue.pop();

        if (order.empty()) {
            order.push_back(c.type);
            if (c.count > 1) {
                Cake n = {c.count - 1, c.type};
                cake_queue.push(n);
            }
        } else if (cake_queue.empty()) {
            for (int i = 0; i < c.count; i++) {
                order.push_back(c.type);
            }
        } else {
            if (c.type == order.back()) {
                Cake second = cake_queue.top();
                cake_queue.pop();
                order.push_back(second.type);
                if (second.count > 1) {
                    Cake n = {second.count - 1, c.type};
                    cake_queue.push(n);
                }
                cake_queue.push(c);
            } else {
                order.push_back(c.type);
                if (c.count > 1) {
                    Cake n = {c.count - 1, c.type};
                    cake_queue.push(n);
                }
            }
        }
    }

    int ans = 0;
    rep(i, order.size() - 1) {
        if (order[i] == order[i + 1]) {
            ans++;
        }
    }

    cout << ans << endl;

}
