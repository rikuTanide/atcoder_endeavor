#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
//typedef long long ll;
typedef long long ll;
//typedef pair<int, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = 10e15;
const ll MINF = -10e10;
//const int INF = INT_MAX / 100;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("~/Downloads/02.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;
const int mod = 1000000007;
const double PI = 3.14159265358979323846;

typedef pair<char, char> P;


bool is_match(string &s, int i, char first, char second) {
    int j = i - 1;
    if (j == -1) return false;
    return s[j] == first && s[i] == second;
}

int check(P p, P q, string s, int n) {
    int ans = 0;
    rep(i, n) {
        if (is_match(s, i, p.first, p.second)) {
            s[i] = '.';
        } else if (is_match(s, i, q.first, q.second)) {
            s[i] = '.';
        } else {
            ans++;
        }

    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;


    vector<char> commands = {'A', 'B', 'X', 'Y'};


    vector<P> replace;
    for (char c : commands) {
        for (char d : commands) {
            replace.push_back(P(c, d));
        }
    }

    vector<pair<P, P>> candidates;
    for (P p : replace) {
        for (P q : replace) {
            candidates.emplace_back(p, q);
        }
    }


    int ans = n;
    for (pair<P, P> &p : candidates) {
        int now = check(p.first, p.second, s, n);
        cmin(ans, now);
    }
    cout << ans << endl;
}

