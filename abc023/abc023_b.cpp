#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;

int main() {

    int n;
    string s;
    cin >> n >> s;


    if (n % 2 == 0) {
        cout << -1 << endl;
        return 0;
    }


    char center = s[n / 2];
    if (center != 'b') {
        cout << -1 << endl;
        return 0;

    }

    string front = "";

    vector<char> front_set = {'a', 'c', 'b',};
    for (int i = 0; i < n / 2; i++) {
        front += front_set[i % 3];
    }
    reverse(front.begin(), front.end());


    string back = "";
    vector<char> back_set = {'c', 'a', 'b'};
    for (int i = 0; i < n / 2; i++) {
        back += back_set[i % 3];
    }

    if (s.substr(0, n / 2) != front) {
        cout << -1 << endl;
        return 0;
    }
    if (s.substr(n / 2 + 1) != back) {
        cout << -1 << endl;
        return 0;
    }

    cout << n / 2 << endl;


}
