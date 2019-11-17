#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = 1001001001;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)

typedef tuple<string, int, int> T;

int main() {
    int n, m;
    cin >> n >> m;

    vector<ll> cards(n);
    rep(i, n) {
        cin >> cards[i];
    }
    sort(cards.begin(), cards.end());


    vector<P> changes(m);
    rep(i, m) {
        ll b, c;
        cin >> b >> c;
        changes.emplace_back(c, b);
    }
    sort(changes.rbegin(), changes.rend());

    int it = 0;
    [&] {
        for (auto p : changes) {
            for (int i = 0; i < p.second; i++) {
                if (cards[it] >= p.first)return;
                cards[it] = p.first;
                it++;
                if (it == n - 1) {
                    return;
                }
            }
        }
    }();

    cout << accumulate(cards.begin(), cards.end(), 0ll) << endl;
}

