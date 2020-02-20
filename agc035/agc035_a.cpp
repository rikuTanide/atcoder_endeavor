#include <bits/stdc++.h>
#include <cmath>

//using namespace boost::multiprecision;
using namespace std;
//typedef long long ll;
//typedef unsigned long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
//typedef pair<int, int> P;
//typedef pair<ll, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX / 100;
//const ll INF = (1ll << 31) - 1;
//const ll INF = 1e15;
//const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
//typedef pair<int, int> P;
//typedef pair<double, double> P;
#define ret() return 0;

bool contain(set<char> &s, char a) { return s.find(a) != s.end(); }

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
const int mod = 1000000007;
//const ll mod = 1e10;
typedef priority_queue<long long, vector<long long>, greater<long long> > PQ_ASK;

int main() {
    typedef unsigned long long ll;
    int n;
    cin >> n;

    vector<ll> caps(n);
    rep(i, n)cin >> caps[i];

    map<ll, int> m;
    for (ll c: caps) m[c]++;


    if (m.find(0) != m.end() && m[0] == n) {
        cout << "Yes" << endl;
        ret();
    }

    if (n % 3 != 0) {
        cout << "No" << endl;
        ret();
    }

    vector<ll> numbers, counts;
    for (auto e : m) {
        numbers.push_back(e.first);
        counts.push_back(e.second);
    }

    if (numbers.size() == 2) {
        if (numbers[0] == 0 && counts[1] == 2 * n / 3) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        ret();
    }

    if (numbers.size() == 3) {
        if ((numbers[0] ^ numbers[1] ^ numbers[2] == 0) && counts[0] == n / 3 && counts[1] == n / 3 &&
            counts[2] == n / 3) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        ret();
    }

    cout << "No" << endl;

}

