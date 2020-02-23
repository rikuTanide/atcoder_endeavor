#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
//using namespace boost::multiprecision;
using namespace std;
typedef long long ll;
//typedef unsigned long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
//typedef pair<int, int> P;
//typedef pair<ll, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX / 100;
//const ll INF = (1ll << 31) - 1;
const ll INF = 1e15;
//const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
//typedef pair<int, int> P;
//typedef pair<double, double> P;
#define ret() return 0;

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const int mod = 1000000007;
//const ll mod = 1e10;
typedef priority_queue<long long, vector<long long>, greater<long long> > PQ_ASK;

ll calc(string s) {
    stack<ll> st;
    st.push(0);
    for (char c : s) {
        if (c == '+') {
            st.push(0);
        } else {
            int i = c - '0';
            st.top() *= 10;
            st.top() += i;
        }
    }

    ll ans = 0;
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
    return ans;
}

int main() {
    string s;
    cin >> s;

    ll k;
    cin >> k;

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c == 'a') continue;
        int m = 'z' - c;
        m++;
        if (k >= m) {
            k -= m;
            s[i] = 'a';
        }
    }

    ll b = s.back() - 'a';
    b += k;
    b %= 26;
    s.back() = 'a' + b;
    cout << s << endl;
}
