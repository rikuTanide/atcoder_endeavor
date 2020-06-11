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

bool contain(set<char> &s, char a) { return s.find(a) != s.end(); }

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//const ll mod = 1e10;
typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;


bool is_kaibun(vector<int> &hs, int i, int j) {
    int k = hs[i] ^hs[j + 1];
    int f = __builtin_popcount(k);
    return f <= 1;
}

int main() {
    string s;
    cin >> s;
    int n = s.size();

    vector<int> hs(n + 1, 0);

    rep(i, n + 1) {
        if (i == 0) continue;

        char c = s[i - 1];
        int j = c - 'a';

        int next = hs[i - 1] ^(1 << j);
        hs[i] = next;
    }


    vector<int> dp(n + 1, -1);
    dp[0] = 0;

    auto set = [&](int i, int k) {
        if (dp[i] == -1) dp[i] = k;
        else
            cmin(dp[i], k);
    };

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (is_kaibun(hs, i, j)) set(j + 1, dp[i] + 1);
        }
    }

    cout << dp[n] << endl;

}
