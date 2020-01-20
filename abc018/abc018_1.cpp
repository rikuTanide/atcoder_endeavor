#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = 10e15;
const ll MINF = -10e10;
//const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("~/Downloads/02.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;


class Order {
    vector<int> v;
    vector<int> order;
public:
    Order(vector<int> &v) : v(v), order(v.size()) {
        vector<P> tmp(v.size());
        rep(i, v.size()) {
            tmp[i].first = v[i];
            tmp[i].second = i;
        }
        sort(tmp.rbegin(), tmp.rend());
        rep(i, v.size()) {
            order[tmp[i].second] = i;
        }
    }

    int index(int i) {
        return order[i];
    }

};

int main() {

    vector<int> v(3);
    rep(i, 3)cin >> v[i];
    Order o(v);

    rep(i, 3) {
        cout << o.index(i) + 1 << endl;
    }

}