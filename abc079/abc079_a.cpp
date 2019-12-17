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
//typedef pair<int, int> P;

vector<int> keta(int n) {
    vector<int> k(10, 0);
    for (int i = 0; i < 3; i++) {
        k[n % 10]++;
        n /= 10;
    }
    return k;
}

int main() {

    int n;
    cin >> n;

    for (int i : keta(n / 10)) {
        if (i >= 3) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    for (int i : keta(n % 1000)) {
        if (i >= 3) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

}