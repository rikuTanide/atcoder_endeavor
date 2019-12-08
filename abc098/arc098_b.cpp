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
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;
//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

int main() {
    ll n;
    cin >> n;
//    ifstream myfile("C:\\Users\\riku\\Downloads\\subtask_1_30.txt");
//    myfile >> n;

    vector<ll> numbers(n);
    rep(i, n) {
        cin >> numbers[i];
//        myfile >> numbers[i];
    }

    ll ans = 0;

    ll sums = 0;
    ll xors = 0;

    queue<ll> waiting;
    queue<ll> use;
    for (int i = 0; i < n; i++) {
        waiting.push(numbers[i]);
    }

    while (!waiting.empty()) {
        ll wf = waiting.front();
        ll n_sum = sums + wf;
        ll n_xor = xors ^wf;

        if (n_sum == n_xor) {
            sums = n_sum;
            xors = n_xor;
            waiting.pop();
            use.push(wf);
            ans += use.size();
        } else {
            ll uf = use.front();
            sums -= uf;
            xors = sums;
            use.pop();
        }

    }

    cout << ans << endl;

}