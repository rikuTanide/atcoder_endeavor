#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
//using namespace boost::multiprecision;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
const ll INF = 1e15;
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
const int mod = 1000000007;
//const ll mod = 1e10;
typedef priority_queue<string, vector<string>, greater<string> > PQ_ASK;

struct City {
    ll id, prefecture, year, rank;
};

int main() {

    int n, m;
    cin >> n >> m;
    vector<City> cities(m);
    rep(i, m) cities[i].id = i;
    rep(i, m) cin >> cities[i].prefecture >> cities[i].year;
    sort(cities.begin(), cities.end(), [](City &c, City &d) {
        if (c.prefecture != d.prefecture) return c.prefecture < d.prefecture;
        return c.year < d.year;
    });
    cities[0].rank = 0;
    for (int i = 1; i < n; i++) {
        if (cities[i - 1].prefecture != cities[i].prefecture) {
            cities[i].rank = 0;
        } else {
            cities[i].rank = cities[i - 1].rank + 1;
        }
    }
    sort(cities.begin(), cities.end(), [](City &c, City &d) {
        return c.id < d.id;
    });

    for (City &c : cities) {
        printf("%06lld%06lld\n", c.prefecture, c.rank + 1);
    }

}