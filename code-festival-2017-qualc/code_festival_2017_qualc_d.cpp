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


bool is_kaibun(string &s, int i, int j) {
    set<char> st;
    for (int k = i; k <= j; k++) {
        if (contain(st, s[k])) st.erase(s[k]);
        else st.insert(s[k]);
    }
    return st.size() <= 1;
}

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> dp(n + 1, -1);
    dp[0] = 0;

    auto set = [&](int i, int k) {
        if (dp[i] == -1) dp[i] = k;
        else
            cmin(dp[i], k);
    };

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (is_kaibun(s, i, j)) set(j + 1, dp[i] + 1);
        }
    }

    cout << dp[n] << endl;

}
