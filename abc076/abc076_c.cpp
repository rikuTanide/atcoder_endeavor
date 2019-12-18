#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = 10e15;
const ll MINF = -10e10;
const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;

bool check(string s, string t, int i) {
    /*
    for (int j = 0; j < t.size(); j++) {
        cout << s[i + j] ;
    }
    cout << endl;
    for (int j = 0; j < t.size(); j++) {
        cout << t[j];
    }
    cout << endl;
    return true;
     */

    for (int j = 0; j < t.size(); j++) {
        char a = s[i + j];
        char b = t[j];
        if (a == '?') continue;
        if (a == b) continue;
        return false;
    }
    return true;

}

string merge(string s, string t, int i) {
    return s.substr(0, i) + t + s.substr(i + t.size());
}

string replace(string s) {
    for (int j = 0; j < s.size(); j++) {
        if (s[j] == '?') {
            s[j] = 'a';
        }
    }
    return s;

}

int main() {
    string s, t;
    cin >> s >> t;

    vector<string> candidate;

    for (int i = 0; i <= s.size() - t.size(); i++) {
        bool b = check(s, t, i);
        if (b) {
            string n = merge(s, t, i);
            string now = replace(n);
            candidate.push_back(now);
        }
    }

    if(candidate.empty()) {
        cout << "UNRESTORABLE" << endl;
        return 0;
    }

    string ans = *min_element(candidate.begin(), candidate.end());

    cout << ans << endl;

}
