#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;
const int INF = 1001001001;


int main() {

    int n;
    cin >> n;

    vector<int> values (n);
    rep(i, n) cin >> values[i];
    sort(values.begin(), values.end());

    double sum = values[0];
    for(int i = 1 ; i < n - 1 ; i ++) {
        sum = (sum + values[i]) / 2;
    }
    sum = (sum + values[n -1]) / 2;
    printf("%.10f", sum);


}
