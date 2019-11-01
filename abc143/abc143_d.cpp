#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;

int main() {

    int n;
    cin >> n;

    vector<int> ls(n);

    rep(i, n) {
        int l;
        cin >> l;
        ls[i] = l;
    }
    int count = 0;
    for (int x = 0; x < n; x++) {
        int a = ls[x];
        for (int y = x + 1; y < n; y++) {
            int b = ls[y];
            for (int z = y + 1; z < n; z++) {

                int c = ls[z];

                if (a >= (b + c)) {
                    continue;
                }
                if (b >= (a + c)) {
                    continue;
                }
                if (c >= (b + a)) {
                    continue;
                }
                count++;
            }
        }
    }


    cout << count << endl;

}

