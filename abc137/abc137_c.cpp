#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())

int main() {

    int n;
    cin >> n;
    vector<string> strs(n);

    rep(i, n) {
        cin >> strs[i];
    }

    vector<int[26]> counts(n);

    for (int i = 0; i < n; i++) {
        for (char c : strs[i]) {
            int index = c - 'a';
            counts[i][index]++;
        }
    }
    int ans = 0;

    for (int x = 0; x < n; x++) {
        for (int y = x + 1; y < n; y++) {

            bool b = true;
            for (int z = 0; z < 26; z++) {
                if (counts[x][z] != counts[y][z]) {
                    b = false;
                    break;
                }
            }
            if (b)ans++;

        }
    }
    cout << ans << endl;
}
