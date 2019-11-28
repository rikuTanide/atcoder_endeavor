#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = 10e10;
const ll MINF = -10e10;
//const int INF = INT_MAX;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)

typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;
const int mod = 1000000007;
//ifstream myfile("C:\\Users\\riku\\Downloads\\01.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;


int main() {
    string s, t;

    cin >> s >> t;

    vector<char> q(26, 27);
    vector<char> r(26, 27);

    for (int i = 0; i < s.size(); i++) {
        char sc = s[i] - 'a';
        char tc = t[i] - 'a';

        if (q[sc] == 27) {
            q[sc] = tc;
        } else {
            if (tc != q[sc]) {
                cout << "No" << endl;
                return 0;
            }
        }
//        if (r[tc] == 0) {
//            r[i] = sc;
//        } else {
//            if (sc != r[tc]) {
//                cout << "No" << endl;
//                return 0;
//            }
//        }
    }


    cout << "Yes" << endl;
}
