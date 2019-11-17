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

const int mod = 1e9 + 7;


int main() {
    int n, k;
    cin >> n >> k;

    double p = 0;

    for (int i = 1; i <= n; i++) {
        // iを何回２倍したらkを超えるか
        int c = 0;
        int s = i;
        while (true) {
            if (s >= k) {
                break;
            }
            s *= 2;
            c++;
        }
        double ap = 1 / pow(2, c);
        p += ap;
    }

    cout << printf("%.10f", p / n) << endl;
}

