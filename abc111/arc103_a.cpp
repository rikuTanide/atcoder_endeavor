#include <bits/stdc++.h>
#include <cmath>

//using namespace boost::multiprecision;
using namespace std;
typedef long long ll;
//typedef unsigned long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
typedef pair<int, int> P;
//typedef pair<ll, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX / 100;
//const ll INF = (1ll << 31) - 1;
const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
//typedef pair<int, int> P;
//typedef pair<double, double> P;

bool contain(set<ll> &s, ll a) { return s.find(a) != s.end(); }

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
const int mod = 1000000007;
typedef priority_queue<long long, vector<long long>, greater<long long> > PQ_ASK;

struct Frequency {
    int n, f;
};

vector<Frequency> frequency(map<int, int> &m) {
    vector<Frequency> res;
    for (auto e : m) {
        res.push_back({e.first, e.second});
    }
    sort(res.begin(), res.end(), [](Frequency f, Frequency g) {
        return f.f > g.f;
    });
    res.push_back({0, 0});
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    rep(i, n) cin >> numbers[i];


    vector<Frequency> a, b;
    {
        map<int, int> m;
        rep(i, n) {
            if (i % 2 == 0) continue;
            m[numbers[i]]++;
        }
        a = frequency(m);
    }
    {
        map<int, int> m;
        rep(i, n) {
            if (i % 2 == 1) continue;
            m[numbers[i]]++;
        }
        b = frequency(m);
    }

    int n2 = n / 2;
    if (a.front().n != b.front().n) {
        cout << (n2 - a.front().f) + (n2 - b.front().f) << endl;
    } else if (a[1].f > b[1].f) {
        cout << (n2 - a[1].f) + (n2 - b.front().f) << endl;
    } else {
        cout << (n2 - a.front().f) + (n2 - b[1].f) << endl;
    }

}

