#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
typedef pair<int, int> P;
const ll INF = 1001001001;

const int mod = 1000000007;

int main() {
    int n;
    cin >> n;

    vector<int> ps(n);
    rep(i, n) {
        cin >> ps[i];
    }

    int count = 0;
    rep(i, n - 2) {

        int a = ps[i];
        int b = ps[i + 1];
        int c = ps[i + 2];

        if ((a < b && b < c) || (c < b && b < a)) {
            count++;
        }
    }

    cout << count << endl;


}