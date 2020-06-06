#include <bits/stdc++.h>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
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

//const ll mod = 1e10;
typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;

bool knapsack(vector<ll> &cards, int i, ll k) {
    ll a = cards[i];
    int n = cards.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, false));
    dp[0][0] = true;

    auto set = [&](int y, ll x) -> bool {
        if (y > n) return false;
        if (x > k) return false;


        dp[y][x] = true;
        return false;
    };

    rep(y, n) {
        if (y == i) {
            dp[y + 1] = dp[y];
            continue;
        }
        rep(x, k + 1) {
            if (!dp[y][x]) continue;
            // y を使わない
            set(y + 1, x);
            // yを使う
            set(y + 1, cards[y] + x);
        }
    }

    for (int j = max(k - a, 0ll); j < k; j++) {
        if (dp[n][j]) return true;
    }

    return false;

}


int main() {
    int n;
    ll k;
    cin >> n >> k;

    vector<ll> cards(n);
    rep(i, n) cin >> cards[i];

    sort(cards.begin(), cards.end());

    int floor = 0, ceil = n - 1;

    if (knapsack(cards, k, floor)) {
        cout << 0 << endl;
        ret();
    }
    if (!knapsack(cards, k, ceil)) {
        cout << n << endl;
        ret();
    }

    __throw_runtime_error("");
    while (floor + 1 < ceil) {
        int mid = (floor + ceil) / 2;
        bool b = knapsack(cards, mid, k);
    }

}