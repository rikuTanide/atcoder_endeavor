#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
typedef long long ll;

const int INF = 1001001001;

int main() {

    int a, b, c;
    cin >> a >> b >> c;

    cout << max(0, c - (a - b)) << endl;

}
