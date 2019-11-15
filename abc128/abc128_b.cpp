#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
typedef pair<int, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = 1001001001;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)

typedef tuple<string, int, int> T;

int main() {

    int n;
    cin >> n;

    vector<T> ts;

    rep(i, n) {
        string c;
        int p;
        cin >> c;
        cin >> p;
        p = -p;
        T t(c, p, i + 1);
        ts.push_back(t);
    }

    sort(ts.begin(), ts.end());

    for (auto t : ts) {
        cout << get<2>(t) << endl;
    }
}

