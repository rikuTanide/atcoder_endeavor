#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = 10e10;
const ll MINF = -10e10;
const int INF = INT_MAX;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)
typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;
const int mod = 1000000007;
//ifstream myfile("C:\\Users\\riku\\Downloads\\01.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;

int main() {
    int n, m;
    cin >> n >> m;

    set<tuple<ll, int, int>> cities; // <prefecture, year, index>

    rep(i, m) {
        ll y;
        int p;
        cin >> p >> y;
        tuple<ll, int, int> city(p, y, i);
        cities.insert(city);
    }

    set<tuple<int, int, int>> city_ranks;// <index, prefecture, rank>
    int before_prefecture;
    int before_rank = 1;
    {
        auto top = *cities.begin();
        int prefecture = get<0>(top);
        int index = get<2>(top);
        tuple<int, int, int> t(index, prefecture, 1);
        city_ranks.insert(t);
        before_prefecture = prefecture;
    }

    for (auto it = ++cities.begin(); it != cities.end(); it++) {
        auto city = *it;
        int prefecture = get<0>(city);
        int index = get<2>(city);
        int rank;
        if (before_prefecture == prefecture) {
            rank = ++before_rank;
        } else {
            rank = 1;
            before_rank = 1;
            before_prefecture = prefecture;
        }
        tuple<int, int, int> t(index, prefecture, rank);
        city_ranks.insert(t);
    }

    for (auto p : city_ranks) {
        int prefecture = get<1>(p);
        int rank = get<2>(p);
        cout << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
    }

}

