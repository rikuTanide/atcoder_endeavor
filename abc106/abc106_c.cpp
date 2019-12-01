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
//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;

int factorize(int n) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    string s;
    cin >> s;
    ll k;
    cin >> k;


    int last_1 = -1;
    char first_1_igai = 0;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c != '1') {
            first_1_igai = c;
            break;
        } else {
            last_1 = i;
        }
    }

    if (k- 1 <= last_1) {
        cout << '1' << endl;
    } else {
        cout << first_1_igai << endl;
    }

}