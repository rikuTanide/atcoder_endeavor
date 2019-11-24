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

const int mod = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> ls(m);
    rep(i, m) {
        int l;
        cin >> l;
        ls[i] = l;
    }
    sort(ls.begin(), ls.end());
    int diff = ls[0];
    rep(i, m) {
        ls[i] -= diff;
    }
    // 間に合わなかったら二分探索する

    priority_queue<int, vector<int>, greater<int> > queue;
    rep(i, m) queue.push(ls[i]);

    for (int i = 0;; i++) {
        bool check = [&] {
            priority_queue<int, vector<int>, greater<int> > qu(queue);
            int nokori = i;
            for (int j = 0; j < n; j++) {
                int now = qu.top();
                qu.pop();

                while (!qu.empty() && (qu.top() - now) <= nokori) {
                    int next = qu.top();
                    qu.pop();
                    nokori -= (next - now);
                    now = next;
                }
                if (qu.empty()) break;
            }
            return qu.empty();
        }();

        if (check) {
            cout << i << endl;
            return 0;
        }

    }

}

