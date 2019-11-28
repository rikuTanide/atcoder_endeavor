#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
typedef pair<int, int> P;
//typedef pair<ll, ll> P;
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

    map<int, int> odd;
    map<int, int> even;

    rep(i, n) {
        int v;
        cin >> v;
        if (i % 2 == 0) {
            even[v]++;
        } else {
            odd[v]++;
        }
    }

    vector<P> odd_sort;
    vector<P> even_sort;

    for (auto p : odd) {
        P np(p.second, p.first);
        odd_sort.push_back(np);
    }
    odd_sort.push_back(P(0, 0));
    sort(odd_sort.rbegin(), odd_sort.rend());

    for (auto p : even) {
        P np(p.second, p.first);
        even_sort.push_back(np);
    }
    even_sort.push_back(P(0, 0));
    sort(even_sort.rbegin(), even_sort.rend());

    if (even_sort[0] == odd_sort[0]) {

        int ans;
        {
            // oddの一番とevenの二番を使う場合
            int odd_change = (n / 2) - odd_sort[0].first;
            int even_change = (n / 2) - even_sort[1].first;
            ans = odd_change + even_change;
        }
        {
            // oddの二番とevenの一番を使う場合
            int odd_change = (n / 2) - odd_sort[1].first;
            int even_change = (n / 2) - even_sort[0].first;
            ans = min(ans, odd_change + even_change);
        }

        cout << ans << endl;
    } else {
        int odd_change = (n / 2) - odd_sort[0].first;
        int even_change = (n / 2) - even_sort[0].first;
        int ans = odd_change + even_change;
        cout << ans << endl;
    }

}
