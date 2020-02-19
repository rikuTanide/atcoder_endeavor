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
typedef pair<int, int> P;
//typedef pair<ll, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX / 100;
//const ll INF = (1ll << 31) - 1;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
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
    string s;
    cin >> s;

    if (s == "zyxwvutsrqponmlkjihgfedcba") {
        cout << -1 << endl;
        ret();
    }
    if (s.size() != 26) {
        set<char> used;
        rep(i, 27) used.insert('a' + i);
        for (char c : s) used.erase(c);
        char c = *used.begin();
        cout << s + c << endl;
        ret();
    }

    stack<char> st;
    for (char c : s) st.push(c);

    set<char> used;

    [&]() {
        while (!st.empty()) {
            char c = st.top();
            for (char d : used) {
                if (d > c) {
                    st.top() = d;
                    return;
                }
            }
            st.pop();
            used.insert(c);
        }
    }();

    vector<char> ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    for (char c : ans) cout << c;

}