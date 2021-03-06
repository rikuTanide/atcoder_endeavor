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
const ll MINF = LONG_LONG_MIN;
const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<char> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;


int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    rep(i, n)cin >> numbers[i];

    int ave = accumulate(numbers.begin(), numbers.end(), 0) / n;
    int ans = 0;
    {
        for (int num : numbers) {
            int score = (num - ave) * (num - ave);
            ans += score;
        }
    }
    {
        ave++;
        int now = 0;
        for (int num : numbers) {
            int score = (num - ave) * (num - ave);
            now += score;
        }
        cmin(ans, now);
    }
    cout << ans << endl;

}