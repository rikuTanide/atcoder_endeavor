#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;

const int INF = 1001001001;


int main() {

    int n, k, q;

    cin >> n >> k >> q;

    vector<int> points = vector<int>(n, k);

    rep(i, q) {
        int a;
        cin >> a;
        a--;
        rep(j, n) {
            if (j != a) {
                points[j]--;
            }
        }
    }

    for (int point : points) {
        cout << (point <= 0 ? "No" : "Yes") << endl;
    }

}
