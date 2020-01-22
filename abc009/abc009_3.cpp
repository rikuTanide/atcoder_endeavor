#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX / 100;
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

bool check(string s, string t, char c, int k) {
    string nt = t + c;
    vector<int> s_counts(26, 0);
    vector<int> t_counts(26, 0);

    int diff = 0;
    for (int i = 0; i < nt.size(); i++) {
        if (nt[i] != s[i]) diff++;
    }

    rep(i, s.size()) {
        s_counts[s[i] - 'a']++;
        t_counts[s[i] - 'a']++;
    }
    rep(i, nt.size()) {
        s_counts[s[i] - 'a']--;
        t_counts[nt[i] - 'a']--;
    }

    int match = 0;
    rep(i, 26) {
        int now = min(s_counts[i], t_counts[i]);
        match += now;
    }
    int miss = s.size() - nt.size() - match;

    return diff + miss <= k;

}

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    multiset<char> residue;
    rep(i, n) residue.insert(s[i]);

    string t = "";
    for (int i = 0; i < n; i++) {
        for (char c : residue) {
            if (check(s, t, c, k)) {
                residue.erase(residue.find(c));
                t += c;
                break;
            }
        }
    }

    cout << t << endl;

}
