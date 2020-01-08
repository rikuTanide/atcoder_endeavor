#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef pair<int, int> P;
//typedef pair<ll, ll> P;
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

P count(vector<int> &numbers, int a, int t) {
    int start = a;
    int end = t;
    if (start > end) swap(start, end);
    int t_point = 0;
    int a_point = 0;
    for (int i = start; i <= end; i++) {
        if ((i - start) % 2 == 0) t_point += numbers[i];
        else a_point += numbers[i];
    }

    return P(t_point, a_point);
}

P aoki(vector<int> &numbers, int t) {
    P now(-INF, -INF);
    for (int a = 0; a < numbers.size(); a++) {
        if (a == t) continue;
        P p = count(numbers, a, t);
        if (p.second > now.second) now = p;
    }
    return now;
}

int main() {
    int n;
    cin >> n;

    vector<int> numbers(n);
    rep(i, n)cin >> numbers[i];

    int ans = -INF;
    rep(t, n) {
        P p = aoki(numbers, t);
        cmax(ans, p.first);
    }
    cout << ans << endl;

}
