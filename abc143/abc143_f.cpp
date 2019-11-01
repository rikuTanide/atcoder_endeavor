#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> cards(n);
    rep(i, n) {
        int x;
        cin >> x;
        cards[x - 1]++;
    }

    sort(cards.begin(), cards.end());
    vector<int> somes(n + 1);
    rep(i, n) somes[i + 1] = somes[i] + cards[i];
    for (int k = 1; k <= n; k++) {
        int floor = 0, ceil = n / k + 1;
        while (floor + 1 < ceil) {
            int center = (floor + ceil) / 2;
            bool ok = [&](int center) {
                int i = lower_bound(cards.begin(), cards.end(), center) - cards.begin();
                int sum_i_over = (n - i) * center;
                int sum_i_under = somes[i];
                int sum = sum_i_over + sum_i_under;

                return sum >= center * k;
            }(center);
            if (ok) floor = center; else ceil = center;
        }

        printf("%d\n", floor);
    }


}
