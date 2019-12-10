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
const ll INF = 10e15;
const ll MINF = -10e10;
//const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;

int main() {
    ll a, b, c;
    cin >> a >> b >> c;


    if (c > b) {
        swap(b, c);
    }
    if (b > a) {
        swap(a, b);
    }
    if (c > b) {
        swap(b, c);
    }

    if (a == b && b == c) {
        cout << 0 << endl;
        return 0;
    }

    ll diff_a_b = a - b;
    if (diff_a_b % 2 == 1) {
        c++;
        b--;
        diff_a_b ++;
    }

    ll count_b = diff_a_b / 2;

    ll diff_a_c = a - c;
    ll count_c = (diff_a_c + 1) / 2;

    ll count_a_c = 0;
    if (diff_a_c % 2 == 1) {
        count_a_c = 1;
    }

    ll ans = count_b + count_c + count_a_c;
    cout << ans << endl;

}