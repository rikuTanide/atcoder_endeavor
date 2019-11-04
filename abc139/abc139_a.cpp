#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;

const int INF = 1001001001;

int main() {

    string s, t;
    cin >> s >> t;

    int count = 0;
    for (int i = 0; i < 3; i++) {
        if (s[i] == t[i]) {
            count++;
        }
    }
    cout << count << endl;
}
