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


int main() {
    int n;
    cin >> n;
    ll tn = 1, an = 1;
    rep(i, n) {
        ll t, a;
        cin >> t >> a;

        ll tr = (tn + t - 1) / t;
        ll ar = (an + a - 1) / a;
        ll r = max(tr, ar);

        tn = t * r;
        an = a * r;

    }
    cout << tn + an << endl;

}
