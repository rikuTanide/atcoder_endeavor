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
    int n;
    cin >> n;
    vector<string> words(n);
    set<string> counts;

    for (int i = 0; i < n; i++) {
        cin >> words[i];
        counts.insert(words[i]);
    }
    if (counts.size() != n) {
        cout << "No" << endl;
        return 0;
    }

    for (int i = 0; i < n - 1; i++) {
        string prev = words[i];
        string next = words[i + 1];
        char pc = prev.back();
        char nf = next[0];
        if(pc != nf) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;

}
