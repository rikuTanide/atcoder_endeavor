#include <bits/stdc++.h>
#include <cmath>

using namespace std;
//typedef long long ll;
typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX;
const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;

// https://kamino.hatenablog.com/entry/cpp-permutation-combination
void foreach_permutation(int n, std::function<void(int *)> f) {
    int indexes[n];
    for (int i = 0; i < n; i++) indexes[i] = i;
    do {
        f(indexes);
    } while (std::next_permutation(indexes, indexes + n));
}


int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    rep(i, n) cin >> a[i];
    rep(i, n) a[i]--;
    vector<int> b(n);
    rep(i, n) cin >> b[i];
    rep(i, n) b[i]--;

    int count = 0;
    int start;
    int end;
    foreach_permutation(n, [&](int *indexes) {
        count++;
        bool ok1 = [&] {
            rep(i, n) {
                if (indexes[i] != a[i]) {
                    return false;
                }
            }
            return true;

        }();
        if (ok1) {
            start = count;
        }
        bool ok2 = [&] {
            rep(i, n) {
                if (indexes[i] != b[i]) {
                    return false;
                }
            }
            return true;
        }();
        if (ok2) {
            end = count;
        }
    });

    cout <<abs(end - start) << endl;

}
