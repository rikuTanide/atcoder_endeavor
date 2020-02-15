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

bool check(int i, string org, string s) {
    for (int j = 0; j < s.size(); j++) {
        if (org[j + i] != s[j]) return false;
    }
    return true;
}

string toAns(int i) {
    switch (i) {
        case 0:
            return "Do";
        case 2:
            return "Re";
        case 4:
            return "Mi";
        case 5:
            return "Fa";
        case 7:
            return "So";
        case 9:
            return "La";
        case 11:
            return "Si";
    }
    __throw_runtime_error("nai");
}

int main() {

    string org = "WBWBWWBWBWBW";
    org += org;
    org += org;
    org += org;


    string s;
    cin >> s;

    for (int i = 0; i < org.size(); i++) {
        bool b = check(i, org, s);
        if (!b) continue;
        cout << toAns(i) << endl;
        return 0;
    }
    __throw_runtime_error("nai1");

}

