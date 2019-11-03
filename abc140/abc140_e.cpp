#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;

const int INF = 1001001001;

int main() {

    int n;

    cin >> n;
    vector<int> a(n);

    rep(i, n) {
        int c;
        cin >> c;
        c--;
        a[i] = c;
    }

    vector<int> indexes(n);

    rep(i, n) {
        indexes[a[i]] = i;
    }

    set<int> upper; // x より大きい赤丸

    ll ans = 0;

    for (int x = n - 1; x >= 0; x--) {
        upper.insert(indexes[x]);
        vector<int> l(2, -1);
        vector<int> r(2, n);
        { // left
            auto it = upper.find(indexes[x]);
            rep(i, 2) {
                if (it == upper.begin()) break;
                it--;
                l[i] = *it;
            }
        }
        { // right
            auto it = upper.find(indexes[x]);
            rep(i, 2) {
                it++;
                if (it == upper.end()) break;
                r[i] = *it;
            }
        }

        vector<int> ls(2);
        vector<int> rs(2);
        ls[0] = l[0] - l[1];
        ls[1] = indexes[x] - l[0];
        rs[0] = r[0] - indexes[x];
        rs[1] = r[1] - r[0];

        ll c = (ll) ls[0] * rs[0] + (ll) ls[1] * rs[1];
        ans += c * (x + 1);
    }

    cout << ans << endl;
}
