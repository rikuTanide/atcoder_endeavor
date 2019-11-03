#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;

const int INF = 1001001001;

int main() {

    int n;
    cin >> n;

    vector<int> b(n - 1);

    rep(i, n - 1) {
        cin >> b[i];
    }

    vector<int> a(n);
    a[n - 1] = b[n - 2];
    for(int i = n - 2 ; i >= 1 ; i --) {
        a[i] = min(b[i], b[i - 1]);
    }

    a[0] = b[0];
    int sum = std::accumulate(a.begin(), a.end(), 0);

    cout << sum << endl;

}
