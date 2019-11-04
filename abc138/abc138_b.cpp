#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;
const int INF = 1001001001;


int main() {

    int n;
    cin >> n;
    double sum = 0.0;

    rep (i, n) {
        int a;
        cin >> a;

        sum += (1.0 / a);

    }

    printf("%.10f", 1.0 / sum);


}
