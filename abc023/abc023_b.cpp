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
//typedef pair<ll, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX / 100;
//const ll INF = (1ll << 31) - 1;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
//typedef pair<int, int> P;
//typedef pair<double, double> P;

//bool contain(set<P> &s, P a) { return s.find(a) != s.end(); }

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
const int mod = 1000000007;
typedef priority_queue<long long, vector<long long>, greater<long long> > PQ_ASK;

int main() {
    int n;
    string s;
    cin >> n >> s;

    if (s.size() % 2 == 0) {
        cout << -1 << endl;
        return 0;
    }

    int hlen = s.size() / 2;

    if (s[hlen] != 'b') {
        cout << -1 << endl;
        return 0;
    }

    string first = s.substr(0, hlen),
            second = s.substr(s.size() / 2 + 1);

    reverse(first.begin(), first.end());

    for (int i = 0; i < hlen; i++) {
        char c = first[i];
        if ((i % 3) == 0) if (c == 'a') continue;
        if ((i % 3) == 1) if (c == 'c') continue;
        if ((i % 3) == 2) if (c == 'b') continue;

        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < hlen; i++) {
        char c = second[i];
        if ((i % 3) == 0) if (c == 'c') continue;
        if ((i % 3) == 1) if (c == 'a') continue;
        if ((i % 3) == 2) if (c == 'b') continue;

        cout << -1 << endl;
        return 0;
    }


    cout << hlen << endl;


}
