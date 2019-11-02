#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;

int main() {
    int n;
    cin >> n;

    double even = n / 2;
    double odd = n / 2;

    if (n % 2 == 1) {
        odd++;
    }

    double ans = odd / (even + odd);

    cout << printf("%.10f",  ans ) << endl;


}
