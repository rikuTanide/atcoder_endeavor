#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
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
//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;

int main() {
    string s;
    cin >> s;

    if (s[0] != 'A') {
        cout << "WA" << endl;
        return 0;
    }

    bool b = [&] {
        int count = 0;
        for (int i = 2; i < s.size() - 1; i++) {
            if (s[i] == 'C') {
                count++;
            }
        }
        return count == 1;
    }();
    if (!b) {
        cout << "WA" << endl;
        return 0;
    }

    int count = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] <= 'Z') {
            count++;
        }
    }

    if (count != 2) {
        cout << "WA" << endl;
        return 0;
    }

    cout << "AC" << endl;


}
