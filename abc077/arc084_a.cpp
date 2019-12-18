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

struct Part {
    ll size;
    int position;

};

int main() {


    ll n;
    cin >> n;
    vector<Part> parts(3 * n);

    rep(i, n) {
        int a;
        cin >> a;
        parts[i] = {a, 0,};
    }

    rep(i, n) {
        int b;
        cin >> b;
        parts[n + i] = {b, 1,};
    }

    rep(i, n) {
        int c;
        cin >> c;
        parts[n + n + i] = {c, 2,};
    }

    sort(parts.begin(), parts.end(), [](Part p, Part q) {
        if (p.size == q.size) {
            return p.position > q.position;
        }
        return p.size < q.size;
    });

    ll before_0 = 0;
    ll tsusan_0_count = 0;
    ll tsusan_1_count = 0;
    for (ll i = 0; i < (3 * n); i++) {
        if (parts[i].position == 0) {
            before_0++;
        } else if (parts[i].position == 1) {
            tsusan_0_count += before_0;
        } else {
            tsusan_1_count += tsusan_0_count;
        }
    }

    cout << tsusan_1_count << endl;
}
