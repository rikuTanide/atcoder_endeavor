#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
typedef long long ll;

const int INF = 1001001001;

int main() {

    int n;
    cin >> n;

    int dig = log10(n) + 1;

    int sum = 0;
    for (int i = 1; i < dig; i++) {
        if (i % 2 == 0) {
            continue;
        }
        int p = round(pow(10, i - 1));
        int add = p * 9;
        sum += add;
    }

    if (dig % 2 == 1) {
        int other = n - pow(10, dig - 1) + 1;
        sum += other;
    }

    cout << sum << endl;

}
