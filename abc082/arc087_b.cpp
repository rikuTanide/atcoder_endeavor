#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<ll, ll> P;
const ll INF = 10e17;
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

bool knapsack(vector<int> &items, int target) {
    vector<map<int, bool>> dp(items.size() + 1);
    dp[0][0] = true;
    for (int i = 0; i < items.size(); i++) {
        int item = items[i];
        for (auto e : dp[i]) {
            int next1 = e.first + item;
            int next2 = e.first - item;
            dp[i + 1][next1] = true;
            dp[i + 1][next2] = true;
        }
    }
    return dp[items.size()][target];
}

int main() {
    string s;
    int x, y;
    cin >> s >> x >> y;
    vector<int> horizontals, verticals;
    bool d = true;
    int length = 0;
    for (char c : s) {
        if (c == 'F') length++;
        else {
            if (d) horizontals.push_back(length);
            else verticals.push_back(length);
            d = !d;
            length = 0;
        }
    }
    if (d) horizontals.push_back(length);
    else verticals.push_back(length);

    bool b = knapsack(horizontals, x) && knapsack(verticals, y);
    cout << (b ? "Yes" : "No") << endl;

}

